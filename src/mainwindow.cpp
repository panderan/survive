#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawarea.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    DrawArea *drawArea = new DrawArea();

    ui->setupUi(this);
    ui->mainLayout->addWidget(drawArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}
