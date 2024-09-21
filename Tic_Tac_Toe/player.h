#include <iostream>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    std::string name;
    char marker;
    std::vector<int> moves;

public:
    Player(std::string name, char marker)
    {
        this->name = name;
        this->marker = marker;
        this->moves = std::vector<int>(8, 0);
    }

    std::string getName()
    {
        return this->name;
    }

    char getmarker()
    {
        return this->marker;
    }

    std::vector<int> &getMoves()
    {
        return this->moves;
    }
};

#endif