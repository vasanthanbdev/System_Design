#include <iostream>

#include "board.h"
#include "player.h"

int main()
{
    std::cout << "\nWelcome to Tic Tac Toe Game!" << std::endl;

    std::string player1_name;
    std::cout << "\nEnter player1's (X) name: ";
    std::cin >> player1_name;

    std::string player2_name;
    std::cout << "\nEnter player2's (O) name: ";
    std::cin >> player2_name;

    Player player1(player1_name, 'X');
    Player player2(player2_name, 'O');

    Board board;

    bool game = true;
    int move = 1;

    while (move <= 9 && game)
    {
        board.displayBoard();

        if (move % 2 != 0)
        {
            std::cout << "\n"
                      << player1_name << "'s move, please enter the location you want to mark: ";
            int x, y;
            std::cin >> x >> y;

            game = board.move(player1, x, y);
        }
        else
        {
            std::cout << "\n"
                      << player2_name << "'s move, please enter the location you want to mark: ";
            int x, y;
            std::cin >> x >> y;

            game = board.move(player2, x, y);
        }

        move++;
    }

    if (game)
    {
        std::cout << "The match is draw!" << std::endl;
    }

    board.displayBoard();

    return 0;
}