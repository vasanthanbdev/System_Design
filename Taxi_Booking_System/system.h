#include <iostream>
#include <vector>
#include "location.h"
#include "booking.h"
#include "taxi.h"


#ifndef SYSTEM_H
#define SYSTEM_H

class System
{
private:

    LocationList location;
    std::vector<Taxi> taxis;
    std::vector<Booking> bookings;

public:

    System() 
    {
        // generate locations
        char point = 'A';
        for (int i = 0; i < 6; i++) 
        {
            this->location.listAppend(point + i);
        }

        // generate taxis
        for(int i = 1; i < 5; i++) 
        {
            this->taxis.push_back(Taxi(i));
        }

    }

    void displayTaxiDetails();

    void bookTaxi();

    void displayBookings();

};



#endif
