#include<iostream>
#include "system.h"



void System::displayTaxiDetails()
{
    for(auto it = taxis.begin(); it != taxis.end(); it++)
    {
        it->printTaxiDetails();
    }
}


void System::displayBookings()
{
    for(auto it = bookings.begin(); it != bookings.end(); it++)
    {
        it->printBookingDetails();
    }
}