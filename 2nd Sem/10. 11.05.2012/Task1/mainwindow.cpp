#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            table[i][j] = 0;

    QSignalMapper *numMap = new QSignalMapper(this);
    connect(numMap, SIGNAL(mapped(int)), this, SLOT(numClicked(int)));
    for (int i = 0; i < 9; i++)
    {
      //  QString text = QString::number(i);
        buttons[i] = new QPushButton("", this);

    //    buttons[i]->geometry().
        numMap->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), numMap, SLOT(map()));
    }

    for (int i = 0; i < 9; ++i)
        ui->gridLayout->addWidget(buttons[i], i / 3, i % 3);

    connect(ui->restartBut, SIGNAL(clicked()), this, SLOT(restart()));
}

inline bool MainWindow::checkVertical(int x)
{
    for (int i = 0; i < 3; i++)
        if (table[x][i] != player)
            return false;
    return true;
}

inline bool MainWindow::checkHorizontal(int y)
{
    for (int i = 0; i < 3; i++)
        if (table[i][y] != player)
            return false;
    return true;
}

inline bool MainWindow::checkDiagonals()
{
    bool first = true;
    bool second = true;
    for (int i = 0; i < 3; i++)
    {
        first = first & table[i][i] == player;
        second = second & table[3 - i][i] == player;
    }
    return first || second;
}

bool MainWindow::checkWin(int i)
{
    int x = i / 3;
    int y = i % 3;

    return checkVertical(x) || checkHorizontal(y) || checkDiagonals();
}

void MainWindow::numClicked(int i)
{
    if (table[i / 3][i % 3])
        return;

    if (player == 1)
        buttons[i]->setText("X");
    else
        buttons[i]->setText("0");

    table[i / 3][i % 3] = player;
    if (checkWin(i))
    {
        QString s = player == 1 ? "CROSS" : "CIRCLE";
        ui->label->setText(s + " WIN THE GAME!!!");
    }
    player = -player;
}

void MainWindow::restart()
{
    player = 1;
    for(int i = 0; i < 9; i++)
    {
            table[i / 3][i % 3] = 0;
            buttons[i]->setText("");
    }
    ui->label->setText("FIGHT!!!");
}

MainWindow::~MainWindow()
{
    delete ui;
}
