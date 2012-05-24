#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
     QPushButton *buttons[9];
     QSignalMapper *numMap;
     /// current player
     int player;
     int table[3][3];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     /// check current player if he win
     bool checkWin(int i);
     bool checkVertical(int x);
     bool checkHorizontal(int y);
     bool checkDiagonals();
    
private:
    Ui::MainWindow *ui;

public slots:
    void numClicked(int i);
    void restart();
};

#endif // MAINWINDOW_H
