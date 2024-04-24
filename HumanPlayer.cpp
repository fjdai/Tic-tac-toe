#include "Player.h"
#include "HumanPlayer.h"
#include <string>
#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"


HumanPlayer::HumanPlayer(char sym = 'X') : Player(sym) {}
int HumanPlayer::move(Board& board)
{
    int move;
    string temp;
    while (true)
    {
        if (getSymbol() == 'X')
            cout << "Toi luot nguoi choi " << BOLDGREEN << getSymbol() << RESET << endl;
        else if (getSymbol() == 'O')
            cout << "Toi luot nguoi choi " << BOLDRED << getSymbol() << RESET << endl;
        cout << "Nhap so ban muon chon : ";

        while (cin >> temp)
        {   
            bool flag = true;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] <= '0' || temp[i] > '9')
                {
                    cout << "So ban chon nam ngoai pham vi (1->9). Vui long chon lai: ";
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            move = stoi(temp);
            move--;
            if (move >= 0 && move < 9)
            {
                if (board[move] != 'X' && board[move] != 'O')
                {
                    return move;
                }
                else
                {
                    cout << "So da duoc chon roi. Vui long chon lai: ";
                }
            }
            else
            {
                cout << "So ban chon nam ngoai pham vi (1->9). Vui long chon lai: ";
            }
        }
    }
}
void HumanPlayer::winner()
{
    if (getSymbol() == 'X')
        cout << BOLDGREEN << "Nguoi choi " << getSymbol() << " thang!" << RESET << endl;
    else if (getSymbol() == 'O')
        cout << BOLDRED << "Nguoi choi " << getSymbol() << " thang!" << RESET << endl;
}