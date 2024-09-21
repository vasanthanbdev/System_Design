#include <iostream>
#include <vector>
#include <unordered_map>

#include "player.h"

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    std::vector<std::vector<char>> matrix;

public:
    Board()
    {
        this->matrix = std::vector<std::vector<char>>(3, std::vector<char>(3, '_'));
    }

    void displayBoard();

    bool move(Player &player, int x, int y);
};

#endif