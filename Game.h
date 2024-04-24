#pragma once
#include "Board.h"
#include "Player.h"
#include <string>

class Game
{
private:
    Board board;
    Player* player1;
    Player* player2;
    Player* currentPlayer;

public:
    Game(Player* _player1, Player* _player2);
    ~Game();

    void run();
    string end();
};
