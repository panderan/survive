#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include "survive.h"

class DrawArea : public QWidget
{
    Q_OBJECT
public:
    explicit DrawArea(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

};

#endif // DRAWAREA_H
