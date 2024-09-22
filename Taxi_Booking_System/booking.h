#include <iostream>
#include "location.h"

#ifndef BOOKING_H
#define BOOKING_H

class Booking
{
private:
    static int booking_counter;

    int booking_id;
    int customer_id;
    int taxi_no;

    PointNode *pickup_location;
    PointNode *drop_location;

    int pickup_time;
    int drop_time;

public:
    Booking(
        int customer_id,
        int taxi_no,
        PointNode *pickup_location,
        PointNode *drop_location,
        int pickup_time,
        int drop_time)
    {
        this->booking_id = ++booking_counter;
        this->customer_id = customer_id;
        this->taxi_no = taxi_no;
        this->pickup_location = pickup_location;
        this->drop_location = drop_location;
        this->pickup_time = pickup_time;
        this->drop_time = drop_time;
    }

    void printBookingDetails();
};

#endif
