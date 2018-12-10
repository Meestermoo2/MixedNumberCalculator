#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculate.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digitpressed();
    void backspacepressed();
    void CEpressed();
    void Cpressed();
    void evaluatepressed();
    void spacepressed();
    void multiplypressed();
    void dividepressed();
    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
