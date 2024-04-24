#pragma once
#include "Player.h"
#include "Board.h"
class HumanPlayer :
    public Player
{
public:
    HumanPlayer(char sym);
    int move(Board& board);
    void winner();
};
