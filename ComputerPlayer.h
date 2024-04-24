#pragma once
#include "Player.h"
class ComputerPlayer : 
    public Player
{
public:
    ComputerPlayer(char sym);
    int move(Board& board);
    void winner();
};