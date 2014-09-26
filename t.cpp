// g++ -pthread -std=c++11 -Wall -o t t.cpp
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>        /* Definition of uint64_t */

std::mutex lock;
std::condition_variable cond;
int32_t x = 0;

void consumer(int id) {
    for (int i = 0; i < 50; ++i) {
        std::unique_lock<std::mutex> l(lock);
        cond.wait(l, [](){return x > 0;});
        --x;
        std::cout << "Consumer " << id << " fetched " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

void producer(int id) {
    for (int i = 0; i < 75; ++i) {
        {
            std::unique_lock<std::mutex> l(lock);
            ++x;
            cond.notify_one();
        }
        std::cout << "Produced " << id << " produced " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(){
    std::thread p1(producer, 0);
    std::thread c1(consumer, 0);
    p1.join();
    c1.join();
    return 0;
}
