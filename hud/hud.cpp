#include "hud.h"
#include <QPainter>

#define LCD_WIDTH 192
#define LCD_HEIGHT 64

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
