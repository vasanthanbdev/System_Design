#include <bits/stdc++.h>
#include <unistd.h>
#include "ticket.h"

void displayOptions()
{
    std::cout << "\n### Options ###" << std::endl;
    std::cout << "  1. Print Available Tickets  " << std::endl;
    std::cout << "  2. Book Tickets  " << std::endl;
    std::cout << "  3. Print Booked Tickets  " << std::endl;
    std::cout << "  4. Cancel Tickets  " << std::endl;
    std::cout << "  5. Exit  " << std::endl;
}

int main()
{
    std::deque<std::pair<std::string, Passenger>> confirmed_tickets;
    Passenger passenger;
    Ticket ticket;

    std::cout << "\n########## Welcome to Railway Reservation System ##########" << std::endl;
    int choice;
    while (true)
    {
        displayOptions();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ticket.printAvailableTickets();
            break;

        case 2:
            ticket.bookTickets(passenger, confirmed_tickets);
            break;

        case 3:
            ticket.printBookedTickets(confirmed_tickets);
            break;

        case 4:
            ticket.cancelTickets(confirmed_tickets);
            break;

        case 5:
            std::cout << "  Thank You!  " << std::endl;
            exit(0);

        default:
            std::cout << "Enter a valid choice!" << std::endl;
            continue;
        }
    }

    return 0;
}