#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

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
    void evaluatepressed();
    void spacepressed();
    void multiplypressed();
    void dividepressed();
    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
