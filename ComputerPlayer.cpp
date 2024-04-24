#include "ComputerPlayer.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;

#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"


ComputerPlayer::ComputerPlayer(char sym = 'O') : Player(sym) {}
int ComputerPlayer::move(Board& board)
{
    vector<int> emptyCells;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            emptyCells.push_back(i);
        }
    }
    srand(time(NULL));
    if (getSymbol() == 'X')
    {
        cout << "Toi luot may tinh " << BOLDGREEN << getSymbol() << RESET << endl;
        cout << "May tinh " << BOLDGREEN << getSymbol() << RESET << " chon vi tri so ";
    }
    else if (getSymbol() == 'O')
    {
        cout << "Toi luot may tinh " << BOLDRED << getSymbol() << RESET << endl;
        cout << "May tinh " << BOLDRED << getSymbol() << RESET << " chon vi tri so ";
    }
    int tmp = emptyCells[rand() % emptyCells.size()];
    cout << BOLDYELLOW << tmp + 1 << RESET << endl;
    return tmp;
}

void ComputerPlayer::winner()
{
    if (getSymbol() == 'X')
        cout << BOLDGREEN << "May tinh " << getSymbol() << " thang!" << RESET << endl;
    else if (getSymbol() == 'O')
        cout << BOLDRED << "May tinh " << getSymbol() << " thang!" << RESET << endl;
}
