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
    connect(ui->pushButton_Add, SIGNAL(released()), this, SLOT(addpressed()));
    connect(ui->pushButton_Subtract, SIGNAL(released()), this, SLOT(subtractpressed()));
    connect(ui->pushButton_Divide, SIGNAL(released()), this, SLOT(dividepressed()));
    connect(ui->pushButton_Multiply, SIGNAL(released()), this, SLOT(multiplypressed()));
    connect(ui->pushButton_Evaluate, SIGNAL(released()), this, SLOT(evaluatepressed()));
    connect(ui->pushButton_C, SIGNAL(released()), this, SLOT(Cpressed()));
    connect(ui->pushButton_ClearHistory, SIGNAL(released()), this, SLOT(ClearHistorypressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitpressed() // for a generic signal where the text is the same as its ouput, we use this function
{
    //grab the sender's text and append it to the current text.
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;

    newLabel = (ui->Input->text() + button->text());
    ui->Input->setText(newLabel);
}

void MainWindow::backspacepressed()
{
    QString temp;
    temp = ui->Input->text();
    temp.chop(1);
    ui->Input->setText(temp);
}

void MainWindow::CEpressed()
{ // clear entry
    ui->Input->clear();
}

void MainWindow::Cpressed()
{ // clear everything
    ui->Input->clear();
    ui->Eval->clear();
    ui->RPN->clear();
}

void MainWindow::ClearHistorypressed()
{
    ui->History->clear();
}


void MainWindow::evaluatepressed()
{
    try {
        QString newLabel = (ui->Input->text()), history;
        std::string parseString = newLabel.toStdString();
        Parser parser;
        Calculate calc;

        // Parse user input
        parser << parseString;

        // Retrieve RPN expression
        parseString = parser.getString();

        newLabel = history = QString::fromStdString(parseString).replace(QString("_"), QString(" ")); // Create QString obj out of RPN
        ui->RPN->setText(newLabel); // Display RPN expression

        // Calculate RPN expression
        calc << parseString;

        // Retrieve evaluated item
        calc >> parseString;
        history += QString::fromStdString("= " + parseString); // Add to history string
        history.replace(QString("_"), QString(" "));
        ui->Eval->setText(QString::fromStdString("= " + parseString).replace(QString("_"), QString(" "))); // Display Evaluated expression
        history.prepend(ui->History->text() + '\n'); // save current history
        ui->History->setText(history); // add history string to the label
    } catch (Error e) {
        ui->RPN->clear();
        ui->Eval->setText(e.what());
    } catch (...) {
        ui->Eval->setText("An unknown error has occured.");
    }

}

void MainWindow::spacepressed()
{ // used for mixed numbers
    QString newLabel;

    newLabel = (ui->Input->text() + " ");
    ui->Input->setText(newLabel);
}

void MainWindow::subtractpressed()
{
    QString newLabel;

    newLabel = (ui->Input->text() + " - ");
    ui->Input->setText(newLabel);
}

void MainWindow::addpressed()
{
    QString newLabel;

    newLabel = (ui->Input->text() + " + ");
    ui->Input->setText(newLabel);
}

void MainWindow::multiplypressed()
{
    QString newLabel;

    newLabel = (ui->Input->text() + " * ");
    ui->Input->setText(newLabel);
}


void MainWindow::dividepressed()
{
    QString newLabel;

    newLabel = (ui->Input->text() + " / ");
    ui->Input->setText(newLabel);
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
        case Qt::Key_C:
            ui->pushButton_C->released();
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
        case Qt::Key_Return:
            ui->pushButton_Evaluate->released();
            break;
        case Qt::Key_End:
            ui->pushButton_ClearHistory->released();
            break;
//        case Qt::Key_Right: //doesnt really work
//            ui->pushButton_Space->released();
//            break;
//        case Qt::Key_Left: //doesnt really work
//            ui->pushButton_Backspace->released();
//            break;
        default:
            break;
    }
}
