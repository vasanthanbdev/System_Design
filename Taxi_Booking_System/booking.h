#include <iostream>
#include "location.h"

#ifndef BOOKING_H
#define BOOKING_H


class Booking 
{
private:
 
    int booking_id;
    int customer_id;
    int taxi_no;
    
    PointNode* pickup_location;
    PointNode* drop_location;    

    int pickup_time;
    int drop_time;

public:

    Booking(
        int booking_id, 
        int customer_id, 
        int taxi_no, 
        PointNode* pickup_location,
        PointNode* drop_location,
        int pickup_time)
    {
        this->booking_id = booking_id;
        this->customer_id = 0;
        this->taxi_no = taxi_no;
        this->pickup_location = pickup_location;
        this->drop_location = drop_location;
        this->pickup_time = pickup_time;
        this->drop_time = calcDropTime(pickup_location, drop_location);
    }

    int calcDropTime(PointNode* pickup_location, PointNode* drop_location);

    void printBookingDetails();



};



#endif 