#pragma once
#include "Board.h"
class Player
{
private:
    char symbol;

public:
    Player(char _symbol);

    char getSymbol();
    virtual int move(Board& board) = 0;
    virtual void winner() = 0;
};

