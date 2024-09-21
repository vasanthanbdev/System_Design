#include <iostream>

#include "board.h"

void Board::displayBoard()
{
    std::cout << "\nBoard" << std::endl;
    for (const auto &row : this->matrix)
    {
        for (const auto &col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Board::move(Player &player, int x, int y)
{
    bool game = true;

    // get the marker char
    char marker = player.getmarker();

    // checking if the location is already marked
    if (this->matrix[x][y] != '_')
    {
        std::cerr << "Position you entered is already marked!" << std::endl;
    }
    else
    {
        // marking the location
        this->matrix[x][y] = marker;

        std::vector<int> &moves = player.getMoves();

        // increase row count
        moves[x]++;

        // increase col count
        moves[y + 3]++;

        // primary diagonal
        if (x == y)
        {
            moves[6]++;
        }

        if (x + y == 2)
        {
            moves[7]++;
        }

        for (int i = 0; i < 8; i++)
        {
            if (moves[i] == 3)
            {
                game = false;

                std::cout << "\nThe Winner is " << player.getName() << std::endl;
            }
        }
    }

    return game;
}
