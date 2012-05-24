#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

#include "tictactoe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
     QPushButton *buttons[9];
     QSignalMapper *numMap;
     TicTacToe game;
     bool isFinished;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

public slots:
    void numClicked(int i);
    void restart();
};

#endif // MAINWINDOW_H
