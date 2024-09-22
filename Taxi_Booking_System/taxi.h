#include <iostream>

#include "location.h"

#ifndef TAXI_H
#define TAXI_H


class Taxi
{
private:

    int taxi_no;
    bool is_booked;
    int earnings;

public:

    Taxi(int taxi_no)
    {
        this->taxi_no = taxi_no;
        this->is_booked = false;
        this->earnings = 0;

    }

    int getTaxiNo(); 

    int getTaxiStatus();
    
    int getEarnings();

    void setTaxiStatus(bool status);

    void setEarnings(int distance); 

    void printTaxiDetails();


};



#endif
