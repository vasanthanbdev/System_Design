#include <iostream>
#include "system.h"


void displayOptions()
{
    std::cout << "\n********** Welcome to Taxi Booking System **********" << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << "1.Display Taxis" << std::endl;
    std::cout << "2.Book Taxi" << std::endl;
    std::cout << "3.Display Bookings" << std::endl;
    std::cout << "4.Exit" << std::endl;
}


int main() 
{
    System system;
    int choice;

    while (true)
    {
        displayOptions();
        std::cout << "\nEnter you choice: "; std::cin >> choice;

        switch (choice)
        {
        case 1:
            //  display taxi details
            system.displayTaxiDetails();
            break;

        case 2:
            // book a taxi
            break;

        case 3:
            // display all bookings
            system.displayBookings();
            break;

        case 4:
            exit(0);

        default:
            std::cout << "Enter a choice from the above list!" << std::endl;
            break;
        }
    
    }

    return 0;
}