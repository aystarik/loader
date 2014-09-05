#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

enum Stage {
    STAGE_LOAD = 0, // 1
    STAGE_DEOIL, // 2
    STAGE_HOTWASH, // 3
    STAGE_WASH1, // 4
    STAGE_ACTIVATE, // 5
    STAGE_WASH2, // 6
    STAGE_ZINC, // 7
    STAGE_WASH3, // 8
    STAGE_PASSIVATE, // 9
    STAGE_WASH4, // 10
    STAGE_DRYER, // 11
    NUM_STAGES
};

const char *stage_names[NUM_STAGES] = {
    "Загрузка", "Обезжиривание", "Промывка ГВ", "Промывка ХВ#1", "Активация",
    "Промывка ХВ#2", "Цинкование", "Промывка ХВ#3", "Пассивация",
    "Промывка ХВ#4", "Сушка"
};

/* Time to stay in seconds */
const long stage_times[NUM_STAGES] = {
    320/* 5.35min */, 290/* 4.8min */, 270/* 4.4min */, 50/* 0.85min */,
    150/* 2.5min */, 40/* 0.68min */, 1800/* 30min */, 120/* 2min */,
    20/* 0.35min */, 80/* 1.35min */, 240/* 4min */,
};

/* Time to exit in seconds, 0 for "dry" stages, extra for zync */
const long exit_times[NUM_STAGES] = {
    0, 3, 3, 3, 3, 3, 3, 8, 3, 3, 0
};

Stage tank_assign[] = {
    STAGE_LOAD, STAGE_DRYER, STAGE_HOTWASH, STAGE_DEOIL, STAGE_WASH1,
    STAGE_ACTIVATE, STAGE_WASH2, STAGE_PASSIVATE, STAGE_WASH4, STAGE_WASH3,
    STAGE_ZINC, STAGE_ZINC, STAGE_ZINC, STAGE_ZINC};

#define NUM_TANKS (sizeof(tank_assign)/sizeof(tank_assign[0]))
#define NUM_PENDANTS    (NUM_TANKS - 1)

struct Pendant {
    long due; // seconds
    int tid; // tank
    bool prio;
    bool active;
    Pendant() : due(0), tid(-1), prio(false), active(false) {}
//    void enterTank(int t);
//    void leaveTank();
};

static const unsigned rise_time = 11;
static const unsigned hop_time = 4;

static struct Robot {
    unsigned current;
    long due;
    bool idle;
    static long wait;
    static long waitnum;
    Robot() : current(0), idle(true) {}
    void doJob(int pid);
} robot;

enum ProcessState {
    PROCESS_STARTING,
    PROCESS_RUNNING,
    PROCESS_FINISHING,
    PROCESS_STOPPED
};

static struct Pendant pendant[NUM_PENDANTS];

static struct Process {
    /* tanks[x] store pendant index in it or -1 if empty */
    int tanks[NUM_TANKS];
    ProcessState state;
    unsigned num_active;
    Process() : state(PROCESS_STARTING), num_active(8) {
        for (unsigned i = 0; i < num_active; ++i) {
            pendant[i].active = true;
        }
        for (unsigned i = 0; i < NUM_TANKS; ++i) {
            tanks[i] = -1;
        }
        addPendants();
    }
    int nextJob();
    int freeTank(Stage sid);
    void enterTank(int pid, int t);
    void leaveTank(int pid);
    Stage nextStage(Stage sid, bool real = false);
    void bumpPendantAhead(int pid);
    void addPendants();
    bool passAhead(int pass, int prio);
} process;

int Process::freeTank(Stage sid) {
    for (unsigned i = 0; i < NUM_TANKS; ++i) {
        if (tank_assign[i] == sid && tanks[i] == -1)
            return i;
    }
    return -1;
}

long curtime = 0;

void Process::bumpPendantAhead(int pid)
{
    Pendant &p = pendant[pid];
    Stage sid = tank_assign[p.tid];
    sid = nextStage(sid);
    if (freeTank(sid))
        return;
    for (unsigned i = 0; i < NUM_TANKS; ++i) {
        if (tank_assign[i] != sid)
            continue;
        
        int pid_ahead = tanks[i];
        pendant[pid_ahead].prio = true;
        bumpPendantAhead(pid_ahead);
        break;
    }
}

void Process::enterTank(int pid, int tid)
{
    Stage sid = tank_assign[tid];
    Pendant &p = pendant[pid];
    if (sid == STAGE_LOAD && state == PROCESS_FINISHING) {
        p.active = false;
        return;
    }
    p.tid = tid;
    tanks[tid] = pid;
    p.due = curtime + stage_times[sid];
    if (sid == STAGE_WASH3) {
        p.prio = true;
        bumpPendantAhead(pid);
    }
}

void Process::leaveTank(int pid)
{
    Pendant &p = pendant[pid];
    tanks[p.tid] = -1;
    if (tank_assign[p.tid] == STAGE_LOAD) {
        addPendants();
        cout << "depart loader stage!\n";
    }
    p.tid = -1;
    p.due = 0;
    p.prio = false;
}

Stage Process::nextStage(Stage sid, bool real) {
    int s = sid + 1;
    if (s >= NUM_STAGES)
        s = STAGE_LOAD;
    if (!real && s == STAGE_PASSIVATE)
        s = STAGE_WASH4;
    return Stage(s);
}

void Process::addPendants() {
    for (unsigned i = 0; i < NUM_PENDANTS; ++i) {
        Pendant &p = pendant[i];
        if (!p.active)
            continue;
        // special case of entering pendant into the process
        if (p.tid == -1) {
            int tid = freeTank(STAGE_LOAD);
            if (tid != -1)
                enterTank(i, tid);
            // assume single STAGE_LOAD tank
            break;
        }
    }
}

bool Process::passAhead(int pass, int prio) {
    Pendant &p_pass = pendant[pass];
    Pendant &p_prio = pendant[prio];
    int e_current = robot.current;
    long etime = curtime + abs(e_current - p_pass.tid) * hop_time;
    e_current = p_pass.tid;
    Stage sid = tank_assign[p_pass.tid];
    Stage sid_last = process.nextStage(sid);
    do {
        if (etime < p_pass.due)
            etime = p_pass.due;
        etime += exit_times[sid];
        sid = process.nextStage(sid, true);
        int to = process.freeTank(sid);
        etime += abs(to - e_current) * hop_time + 2 * rise_time;
        e_current = to;
    } while (sid != sid_last);
    etime += abs(e_current - p_prio.tid) * hop_time;
    if (etime < p_prio.due) {
        cout << "pass ahead!\n";
        return true;
    }
    return false;
}

int Process::nextJob()
{
    struct Best {
        long due;
        int pid;
    } exact = {LONG_MAX, -1}, prio = {LONG_MAX, -1}, normal = {LONG_MAX, -1};

    cout << "finding next move:" << endl;

    for (unsigned i = 0; i < NUM_PENDANTS; ++i) {
        Pendant &p = pendant[i];
        if (!p.active || p.tid == -1)
            continue;
        Stage sid = tank_assign[p.tid];
        cout << "\tpendant #" << i << " in " << "stage #" << sid << "("
            << stage_names[tank_assign[p.tid]] << ") tank #" << p.tid + 1  << 
            " due in " << p.due  << endl;
        if (freeTank(nextStage(sid)) == -1)
            continue;
        if (sid == STAGE_ZINC) {
            if (p.due < exact.due) {
                exact.due = p.due;
                exact.pid = i;
            }
        } else if (p.prio) {
            if (p.due < prio.due) {
                prio.due = p.due;
                prio.pid = i;
            }
        } else {
            if (p.due < normal.due) {
                normal.due = p.due;
                normal.pid = i;
            }
        }
    }

    robot.idle = false;
    int best = -1;
    if (exact.pid != -1) {
        best = exact.pid;
        cout << "have VIP pendant #" << exact.pid << " due in " << exact.due << endl;
    }

    if (prio.pid != -1) {
        cout << "have hot pendant #" << prio.pid << " due in " << prio.due << endl;
        if (best == -1 || passAhead(prio.pid, best))
            best = prio.pid;
    }

    if (normal.pid != -1) {
        cout << "have pendant #" << normal.pid << " due in " << normal.due << endl;
        if (best == -1 || passAhead(normal.pid, best))
            best = normal.pid;
    }

    if (best == -1)
        robot.idle = true;
    return best;
}

void Robot::doJob(int pid) {
    Pendant &p = pendant[pid];
    Stage sid = tank_assign[p.tid];
    long t = abs(current - p.tid) * hop_time;
    curtime += t;
    current = p.tid;
    cout << curtime << ": robot: прибыл к баку #" << current + 1 << endl;
    Stage sid_last = process.nextStage(sid);
    do {
        if (curtime > p.due)
            cout << "подвес передержан на " << curtime - p.due << " в " << 
                stage_names[sid] << endl;
        else
            curtime = p.due; // advance time to due time
        cout << curtime << ": robot: принял подвес #" << pid << endl;
        curtime += exit_times[sid];
        process.leaveTank(pid);
        sid = process.nextStage(sid, true);
        int to = process.freeTank(sid);
        curtime += abs(to - current) * hop_time + 2 * rise_time;
        current = to;
        cout << curtime << ": robot: прибыл к баку #" << current + 1 << endl;
        process.enterTank(pid, to);
    } while (sid != sid_last);
    idle = true;
}

int main()
{
    for (unsigned i = 0; i < NUM_STAGES; ++i) {
        cout << i << ":\t" << stage_names[i] << ",\ttanks: ";
        for (unsigned j = 0; j < NUM_TANKS; ++j) {
            if ((unsigned)tank_assign[j] == i)
                cout << j + 1 << ", ";
        }
        cout << endl;
    }
    while (curtime < 30000) {
        int pendant = -1;
        if (robot.idle) {
            pendant = process.nextJob();
        }
        if (pendant != -1)
            robot.doJob(pendant);
//        if (curtime > 7 * 3600)
//            process.runout = true;
    }
#if 0
    cout << "Прошло " << pendant[0].count << " подвесок" << endl;
    cout << "Робот ждал " << robot.wait << "c. " << robot.waitnum << " раз." << endl;
#endif
}
