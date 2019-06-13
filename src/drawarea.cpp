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
    QImage welcome(":/image/welcome.png");

    int w = 0, h = 0;
    int squareWidth = 25;

    w = gSur.getWidth();
    h = gSur.getHeight();

    if (w == 0 || h == 0) {
        painter.drawImage(QRect(0, 0,711, 400), welcome);
        return;
    }

    painter.setPen(QPen(Qt::black, 1));
    painter.setBrush(Qt::white);
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <=h; j++) {
            int ret = gSur.getStatus(i,j);
            painter.drawRect((j-1)*squareWidth, (i-1)*squareWidth, 
                             squareWidth, squareWidth);
            if (ret != 0) {
                painter.drawImage(QRect((j-1)*squareWidth+1, 
                                        (i-1)*squareWidth+1, 
                                        squareWidth-1, squareWidth-1), bug);
            }
        }
    }
}
