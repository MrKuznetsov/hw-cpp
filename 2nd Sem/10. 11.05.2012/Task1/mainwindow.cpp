#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    isFinished = false;

    QSignalMapper *numMap = new QSignalMapper(this);
    connect(numMap, SIGNAL(mapped(int)), this, SLOT(numClicked(int)));
    for (int i = 0; i < 9; i++)
    {
        buttons[i] = new QPushButton("", this);
        buttons[i]->setFont(QFont("MS Shell Dlg2", 30));
        numMap->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), numMap, SLOT(map()));
    }

    for (int i = 0; i < 9; ++i)
        ui->gridLayout->addWidget(buttons[i], i / 3, i % 3);

    connect(ui->restartBut, SIGNAL(clicked()), this, SLOT(restart()));
}

void MainWindow::numClicked(int i)
{
    int res = game.set(i);
    if (!res || isFinished)
        return;

    if (res == 1)
        buttons[i]->setText("X");
    else
        buttons[i]->setText("0");

    if (game.checkWin(i))
    {
        QString s = res == 1 ? "CROSS" : "CIRCLE";
        ui->label->setText(s + " WIN THE GAME!!!");
        isFinished = true;
    }
}

void MainWindow::restart()
{
    game.reset();
    isFinished = false;
    for(int i = 0; i < 9; i++)
            buttons[i]->setText("");

    ui->label->setText("FIGHT!!!");
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 9; i++)
        delete buttons[i];
    delete ui;
}
