#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    reset();
}

void TicTacToe::reset()
{
    player = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            table[i][j] = 0;
}

bool TicTacToe::checkWin(int i)
{
    int x = i / 3;
    int y = i % 3;


    return checkVertical(x) || checkHorizontal(y) || checkDiagonals();
}

bool TicTacToe::checkVertical(int x)
{
    for (int i = 0; i < 3; i++)
        if (table[x][i] != -player)
            return false;
    return true;
}

bool TicTacToe::checkHorizontal(int y)
{
    for (int i = 0; i < 3; i++)
        if (table[i][y] != -player)
            return false;
    return true;
}

bool TicTacToe::checkDiagonals()
{
    bool first = true;
    bool second = true;
    for (int i = 0; i < 3; i++)
    {
        first = first & table[i][i] == -player;
        second = second & table[2 - i][i] == -player;
    }
    return first || second;
}

int TicTacToe::set(int i)
{
    if (table[i / 3][i % 3])
        return 0;
    table[i / 3][i % 3] = player;
    player = -player;
    return -player;
}
