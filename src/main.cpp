#include "mainwindow.h"
#include <QApplication>
#include "survive.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    gSur.setSize(0,0);

    return a.exec();
}
