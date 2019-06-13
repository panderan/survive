#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSpinBox>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void handleTimeout();

private slots:
    void on_loadBtn_clicked();
    
    void on_startBtn_clicked();
    
    void on_actionHelp_triggered();
    
    void on_stopBtn_clicked();

    void on_nextBtn_clicked();

private:
    Ui::MainWindow *ui;
    QWidget *drawArea;
    QSpinBox *speedSpinBox;
    QTimer timer;
};

#endif // MAINWINDOW_H
