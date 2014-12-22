#include "hud.h"
#include <QPainter>
#include <QMouseEvent>
#include <stdint.h>

#include <iostream>
#include <vector>

#define LCD_WIDTH 192
#define LCD_HEIGHT 64

struct Sense {
    QRect area;
    unsigned id;
    Sense(unsigned id_, unsigned x, unsigned y, unsigned x1, unsigned y1):
        area(x, y, x1-x, y1-y), id(id_) {}
};

static std::vector<Sense> buttons;

Hud::Hud() : lcd(LCD_WIDTH, LCD_HEIGHT)
{
    pixmap.load(":/images/2gi.png");
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(minimumSizeHint());
    gbrush = QBrush(Qt::green, Qt::SolidPattern);
    rbrush = QBrush(Qt::red, Qt::SolidPattern);
    lcd.fill();
    for (int i = 0; i < 192; ++i) {
        drawPixel(i, i%64);
    }
    // f1-f7 = 59-65
    buttons.emplace_back(0x01000036, 30, 270, 95, 335); // stop (f7)
    buttons.emplace_back(0x01000030, 128, 294, 172, 333); //f1
    buttons.emplace_back(0x01000031,  198, 294, 243, 333); //f2
    buttons.emplace_back(0x01000032,  268, 294, 309, 333); //f3
    buttons.emplace_back(0x01000033,  338, 294, 378, 333); //f4
    buttons.emplace_back(0x01000034,  408, 294, 446, 333); //f5
    buttons.emplace_back(0x01000035,  478, 294, 516, 333); //f6

    buttons.emplace_back(0x31, 78,  366, 119, 408); // 1 (2)
    buttons.emplace_back(0x32, 128, 366, 179, 408); // 2
    buttons.emplace_back(0x33, 183, 366, 226, 408); // 3
    buttons.emplace_back(0x34, 237, 366, 278, 408); // 4
    buttons.emplace_back(0x35, 288, 366, 332, 408); // 5
    buttons.emplace_back(0x36, 78,  418, 119, 462); // 6
    buttons.emplace_back(0x37, 128, 418, 179, 462); // 7
    buttons.emplace_back(0x38, 183, 418, 226, 462); // 8
    buttons.emplace_back(0x39, 237, 418, 278, 462); // 9
    buttons.emplace_back(0x30, 288, 418, 332, 462); // 0 (11)

    buttons.emplace_back(0x01000012, 368, 366, 412, 408); // left (105)
    buttons.emplace_back(0x01000013, 421, 366, 464, 408); // up (103)
    buttons.emplace_back(0x01000014, 474, 366, 518, 408); // right (106)
    buttons.emplace_back(0x01000015, 368, 418, 412, 462); // down (108)
    buttons.emplace_back(0x01000000, 421, 418, 464, 462); // escape (1)
    buttons.emplace_back(0x01000005, 474, 418, 518, 462); // enter (28)
}

QSize Hud::minimumSizeHint() const
{
    return pixmap.size();
}

QSize Hud::sizeHint() const
{
    return pixmap.size();
}

void Hud::drawPixel(int x, int y)
{
    QPainter painter(&lcd);
    painter.drawPoint(x, y);
}



void Hud::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap);
    painter.drawPixmap(116, 96, LCD_WIDTH * 2, LCD_HEIGHT * 2, lcd);
    for (unsigned i = 0; i < 4; ++i) {
        if (!led_on[i])
            continue;
        painter.setBrush((i) ? gbrush : rbrush);
        painter.drawRect(50, 107 + i * 27, 20, 8);
    }
}

void Hud::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;
    std::cerr << "mouse event: press at (" << event->x() << ", " << event->y() << ")\n";
}

//void Hud::mouseMoveEvent(QMouseEvent *event)
//{
//    
//}

void Hud::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;
    std::cerr << "mouse event: release at (" << event->x() << ", " << event->y() << ")\n";
}
