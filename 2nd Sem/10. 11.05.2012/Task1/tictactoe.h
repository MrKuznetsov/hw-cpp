#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();

    bool checkWin(int i);
    bool checkVertical(int x);
    bool checkHorizontal(int y);
    bool checkDiagonals();
    int set(int i);

    void reset();
private:
    int table[3][3];
    int player;
};

#endif // TICTACTOE_H
