#include "Board.h"
#include <vector>
#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"

Board::Board() {
	this->board = vector<char>(9, ' ');
}

void Board::init()
{
    for (int i = 0; i < 9; ++i)
    {
        board[i] = '1' + i;
    }
}

void Board::display()
{
    cout << "\n-------------\n";
    for (int i = 0; i < 9; i += 1)
    {
        if (i % 3 == 0)
            cout << "| ";
        if (board[i] == 'X')
            cout << BOLDGREEN << board[i] << RESET << " | ";
        else if (board[i] == 'O')
            cout << BOLDRED << board[i] << RESET << " | ";
        else
            cout << board[i] << " | ";
        if (i % 3 == 2)
            cout << "\n-------------\n";
    }
}

bool Board::checkWinner(char symbol)
{

    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == symbol)
            return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)
            return true;
    }

    if (board[0] == symbol && board[4] == symbol && board[8] == symbol)
        return true;
    if (board[2] == symbol && board[4] == symbol && board[6] == symbol)
        return true;
    return false;
}

bool Board::isFull()
{
    for (char cell : board)
    {
        if (cell != 'X' && cell != 'O')
        {
            return false;
        }
    }
    return true;
}

char& Board::operator[](int index)
{
    return board[index];
}



