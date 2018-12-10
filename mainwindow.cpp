#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // each button has tied to a signal
    connect(ui->pushButton_0,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_1,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_2,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_3,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_4,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_5,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_6,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_7,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_8,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_9,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_Decimal,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_RightParen,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_LeftParen,SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_CE,SIGNAL(released()), this, SLOT(CEpressed()));
    connect(ui->pushButton_Backspace, SIGNAL(released()), this, SLOT(backspacepressed()));
    connect(ui->pushButton_Space, SIGNAL(released()), this, SLOT(spacepressed()));
    connect(ui->pushButton_Frac, SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_Add, SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_Subtract, SIGNAL(released()), this, SLOT(digitpressed()));
    connect(ui->pushButton_Divide, SIGNAL(released()), this, SLOT(dividepressed()));
    connect(ui->pushButton_Multiply, SIGNAL(released()), this, SLOT(multiplypressed()));
    connect(ui->pushButton_Evaluate, SIGNAL(released()), this, SLOT(evaluatepressed()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitpressed() // for a generic signal where the text is the same as its output, we use this function
{
    //grab the sender's text and append it to the current text.
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;

    newLabel = (ui->Output->text() + button->text());
    ui->Output->setText(newLabel);
}

void MainWindow::backspacepressed()
{
    QString temp;
    temp = ui->Output->text();
    temp.chop(1);
    ui->Output->setText(temp);
}

void MainWindow::CEpressed()
{ // delete everything
    ui->Output->clear();
}

void MainWindow::evaluatepressed()
{
    QString newLabel = (ui->Output->text());
    std::string parseString = newLabel.toStdString();
    Parser temp;
    temp << parseString;
    temp >> parseString;
    newLabel = QString::fromStdString(parseString);
    ui->Input->setText(newLabel);
}

void MainWindow::spacepressed()
{ // used for mixed numbers
    QString newLabel;

    newLabel = (ui->Output->text() + " ");
    ui->Output->setText(newLabel);
}

void MainWindow::multiplypressed()
{
    QString newLabel;

    newLabel = (ui->Output->text() + "*");
    ui->Output->setText(newLabel);
}


void MainWindow::dividepressed()
{
    QString newLabel;

    newLabel = (ui->Output->text() + "/");
    ui->Output->setText(newLabel);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        case Qt::Key_0:
            ui->pushButton_0->released();
            break;
        case Qt::Key_1:
            ui->pushButton_1->released();
            break;
        case Qt::Key_2:
            ui->pushButton_2->released();
            break;
        case Qt::Key_3:
            ui->pushButton_3->released();
            break;
        case Qt::Key_4:
            ui->pushButton_4->released();
            break;
        case Qt::Key_5:
            ui->pushButton_5->released();
            break;
        case Qt::Key_6:
            ui->pushButton_6->released();
            break;
        case Qt::Key_7:
            ui->pushButton_7->released();
            break;
        case Qt::Key_8:
            ui->pushButton_8->released();
            break;
        case Qt::Key_9:
            ui->pushButton_9->released();
            break;
        case Qt::Key_Space: //doesnt really work
            ui->pushButton_Space->released();
            break;
        case Qt::Key_Backspace:
            ui->pushButton_Backspace->released();
            break;
        case Qt::Key_Delete:
            ui->pushButton_CE->released();
            break;
        case Qt::Key_Asterisk:
            ui->pushButton_Multiply->released();
            break;
        case Qt::Key_Slash:
            ui->pushButton_Divide->released();
            break;
        case Qt::Key_Plus:
            ui->pushButton_Add->released();
            break;
        case Qt::Key_Minus:
            ui->pushButton_Subtract->released();
            break;
        case Qt::Key_ParenLeft:
            ui->pushButton_LeftParen->released();
            break;
        case Qt::Key_ParenRight:
            ui->pushButton_RightParen->released();
            break;
        case Qt::Key_Underscore:
            ui->pushButton_Space->released();
            break;
        case Qt::Key_Equal:
            ui->pushButton_Evaluate->released();
            break;
        default:
            break;
    }
}
