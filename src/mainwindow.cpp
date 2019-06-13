#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawarea.h"
#include <QFileDialog>
#include <QLayoutItem>
#include <QMessageBox>
#include <QDebug>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i = 0, cnt = 0;
    drawArea = new DrawArea();

    ui->setupUi(this);
    ui->mainLayout->addWidget(drawArea);
    
    speedSpinBox = NULL;
    cnt = ui->ctrlLayout->count()-1;
    for (i=0; i<cnt; i++) {
        QWidget *widget = ui->ctrlLayout->layout()->itemAt(i)->widget();
        QString objname = widget->objectName();

        if (objname.compare(QString("speedSpinBox")) == 0) {
            speedSpinBox = (QSpinBox *) widget;
        }
    }

    connect(&timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleTimeout()
{
    gSur.calculatorNextTime();
    drawArea->update();

    if (gSur.isDeadWorld()) {
        timer.stop();
    }
}

void MainWindow::on_loadBtn_clicked()
{
    QString filename;
    fstream fstm; 
    int num = 0;
    int w = 0, h = 0;

    filename = QFileDialog::getOpenFileName(this, "Load Data");
    fstm.open(filename.toStdString().c_str());

    fstm >> w >> h;
    gSur.setSize(w, h);

    for (int i=1; i<=w; i++) {
        for (int j=1; j<=h; j++) {
            fstm >> num;
            if (num == 1) {
                gSur.setAliveCell(i,j);
            }
        }
    }

    QLayoutItem *drawarea = ui->mainLayout->layout()->itemAt(0);
    drawarea->widget()->update();
}

void MainWindow::on_startBtn_clicked()
{
    int speed;

    speed = speedSpinBox->text().toInt();
    timer.start(speed);
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::about(this, "About", "\
Survive - Conway life game\n \
\n \
2019.6.13\n");
}

void MainWindow::on_stopBtn_clicked()
{
    timer.stop();
}

void MainWindow::on_nextBtn_clicked()
{
    handleTimeout();
}
