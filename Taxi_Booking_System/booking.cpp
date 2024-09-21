#include <iostream>
#include "booking.h"


int Booking::calcDropTime(PointNode* pickup_location, PointNode* drop_location) 
{
    int distance = 0;

    PointNode* node = pickup_location;
    while (node != drop_location)
    {
        distance++;
        if (pickup_location->point < drop_location->point) 
        {
            node = node->next;
        }
        else 
        {
            node = node->prev;
        }
    }
    
    return distance;
}

void Booking::printBookingDetails()
{
    
}