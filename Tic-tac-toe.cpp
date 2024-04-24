#include <string>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

using namespace std;

int main()
{
    while (true)
    {
        cout << endl
            << "Menu:" << endl;
        cout << "1. NGUOI vs NGUOI" << endl;
        cout << "2. NGUOI vs MAY" << endl;
        cout << "3. MAY vs MAY" << endl;
        cout << "Chon che do thu: ";
        string n;
        cin >> n;
        if (n == "1")
        {
            Player* player1 = new HumanPlayer('X');
            Player* player2 = new HumanPlayer('O');
            Game game(player1, player2);
            game.run();
            string temp = game.end();
            if (temp == "continue")
                continue;
            else if (temp == "break")
                break;
        }
        else if (n == "2")
        {
            Player* player1 = new HumanPlayer('X');
            Player* player2 = new ComputerPlayer('O');
            Game game(player1, player2);
            game.run();
            string temp = game.end();
            if (temp == "continue")
                continue;
            else if (temp == "break")
                break;
        }
        else if (n == "3")
        {
            Player* player1 = new ComputerPlayer('X');
            Player* player2 = new ComputerPlayer('O');
            Game game(player1, player2);
            game.run();
            string temp = game.end();
            if (temp == "continue")
                continue;
            else if (temp == "break")
                break;
        }
        else
        {
            cout << "Lua chon khon hop le. Vui long chon lai!" << endl;
        }
    }
    return 0;
};