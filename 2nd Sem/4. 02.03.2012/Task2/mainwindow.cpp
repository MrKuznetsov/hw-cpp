#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(smthChanged()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(smthChanged()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(smthChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int calc(int a, int b, char o)
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

void MainWindow::smthChanged()
{
    int a = ui->spinBox->value();
    int b = ui->spinBox_2->value();

    char c = ui->comboBox->currentText().data()[0].toAscii();
    int res = calc(a, b, c);

    ui->textEdit->setText(QString::number(res));
}
