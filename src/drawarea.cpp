#include "drawarea.h"
#include "survive.h"
#include <QPainter>
#include <QImage>
#include <QRect>

DrawArea::DrawArea(QWidget *parent) : QWidget(parent)
{

}

void DrawArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage bug(":/image/bug1.png");
    QString helpstr = "Help message";

    int w = 0, h = 0;
    int squareWidth = 25;

    w = gSur.getWidth();
    h = gSur.getHeight();

    if (w == 0 || h == 0) {
        painter.drawText(QRect(0,0,200,200), helpstr);
        return;
    }

    painter.setPen(QPen(Qt::black, 1));
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <=h; j++) {
            int ret = gSur.getStatus(i,j);
            if (ret == 0) {
                painter.setBrush(Qt::white);
                painter.drawRect((j-1)*squareWidth, (i-1)*squareWidth, squareWidth, squareWidth);
            }
            else {
                painter.setBrush(Qt::black);
                painter.drawRect((j-1)*squareWidth+1, (i-1)*squareWidth+1, squareWidth, squareWidth);
                painter.drawImage(QRect((j-1)*squareWidth+1, (i-1)*squareWidth+1, squareWidth-1, squareWidth-1), bug);
            }
        }
    }
}
