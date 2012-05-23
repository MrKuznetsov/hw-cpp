#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = true;

    QSignalMapper *numMap = new QSignalMapper(this);
    connect(numMap, SIGNAL(mapped(int)), this, SLOT(numClicked(int)));
    for (int i = 0; i < 9; ++i)
    {
      //  QString text = QString::number(i);
        buttons[i] = new QPushButton("", this);

    //    buttons[i]->geometry().
        numMap->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), numMap, SLOT(map()));
    }

    for (int i = 0; i < 9; ++i)
        ui->gridLayout->addWidget(buttons[i], i / 3, i % 3);
}

void MainWindow::numClicked(int i)
{
    if (player)
        buttons[i]->setText("X");
    else
        buttons[i]->setText("0");
    player = !player;
}

MainWindow::~MainWindow()
{
    delete ui;
}
