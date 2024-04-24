#pragma once
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <iostream>

using namespace std;

#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"

Game::Game(Player* _player1, Player* _player2)
{
    player1 = _player1;
    player2 = _player2;
    currentPlayer = _player1;
}

Game::~Game()
{
    delete player1;
    delete player2;
}

void Game::run()
{
    board.init();
    while (!board.isFull())
    {
        board.display();
        int move = currentPlayer->move(board);
        board[move] = currentPlayer->getSymbol();
        if (board.checkWinner(currentPlayer->getSymbol()))
        {
            board.display();
            currentPlayer->winner();
            return;
        }
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
    cout << endl
        << BOLDYELLOW << "It's a draw!" << RESET << endl;
}

string Game::end()
{
    while (true)
    {
        cout << endl
            << "1. Choi lai" << endl;
        cout << "2. Ket thuc tro choi" << endl;
        cout << "Lua chon cua ban: ";
        string x;
        cin >> x;
        if (x == "1")
        {
            system("cls");
            return "continue";
        }
        else if (x == "2")
        {
            system("cls");
            return "break";
        }
        else
        {
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
        }
    }
}
