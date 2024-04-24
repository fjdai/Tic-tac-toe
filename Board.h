#pragma once
#include <vector>
using namespace std;

class Board
{
private:
    vector<char> board;

public:
    Board();

    void init();

    void display();

    bool checkWinner(char symbol);

    bool isFull();

    char& operator[](int index);
};

