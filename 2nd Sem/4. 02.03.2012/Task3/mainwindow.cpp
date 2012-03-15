#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    left = 0;
    op = '+';
    valChanged = false;

    ui->setupUi(this);

    QSignalMapper *numMap = new QSignalMapper(this);
    QSignalMapper *opMap = new QSignalMapper(this);
    connect(numMap, SIGNAL(mapped(int)), this, SLOT(digitClicked(int)));
    connect(opMap, SIGNAL(mapped(int)), this, SLOT(opClicked(int)));

    for (int i = 0; i < 10; ++i)
    {
        QString text = QString::number(i);
        buttons[i] = new QPushButton(text, this);
        numMap->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), numMap, SLOT(map()));
    }

    buttons[10] = new QPushButton("C", this);
    opMap->setMapping(buttons[10], 'C');
    connect(buttons[10], SIGNAL(clicked()), opMap, SLOT(map()));
    buttons[11] = new QPushButton("=", this);
    opMap->setMapping(buttons[11], '=');
    connect(buttons[11], SIGNAL(clicked()), opMap, SLOT(map()));

    opMap->setMapping(ui->Plus, '+');
    connect(ui->Plus, SIGNAL(clicked()), opMap, SLOT(map()));
    opMap->setMapping(ui->Minus, '-');
    connect(ui->Minus, SIGNAL(clicked()), opMap, SLOT(map()));
    opMap->setMapping(ui->Mul, '*');
    connect(ui->Mul, SIGNAL(clicked()), opMap, SLOT(map()));
    opMap->setMapping(ui->Div, '/');
    connect(ui->Div, SIGNAL(clicked()), opMap, SLOT(map()));


    for (int i = 0; i < 9; ++i)
        ui->gridLayout->addWidget(buttons[i + 1], i / 3, i % 3);
    ui->gridLayout->addWidget(buttons[0], 3, 0);
    ui->gridLayout->addWidget(buttons[10], 3, 1);
    ui->gridLayout->addWidget(buttons[11], 3, 2);
}

void MainWindow::digitClicked(int i)
{
    if (ui->lineEdit->text().toInt() == 0)
        if (i != 0)
            ui->lineEdit->clear();
        else
            return;
    if (valChanged)
    {
        ui->lineEdit->clear();
        valChanged = false;
    }
   ui->lineEdit->setText(ui->lineEdit->text() + QString::number(i));
}

int Calc(int a, int b, char o)
{
    switch (o)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

void MainWindow::opClicked(int i)
{
    switch (i)
    {
    case '+':
    case '*':
    case '/':
    case '-':
        left = Calc(left, ui->lineEdit->text().toInt(), op);
        ui->lineEdit->setText(QString::number(left));
        valChanged = true;
        op = i;
        break;
    case 'C':
        ui->lineEdit->setText("0");
        left = 0;
        op = '+';
        valChanged = false;
        break;
    case '=':
       left = Calc(left, ui->lineEdit->text().toInt(), op);
       ui->lineEdit->setText(QString::number(left));
       valChanged = true;
       left = 0;
       op = '+';
       break;
    }

}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 12; i++)
        delete buttons[i];
    delete ui;
}
