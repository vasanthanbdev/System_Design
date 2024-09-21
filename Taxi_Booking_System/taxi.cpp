#include <iostream>
#include "taxi.h"


int Taxi::getTaxiNo()
{
    return this->taxi_no;
}

int Taxi::getTaxiStatus()
{
    return this->is_booked;
}

int Taxi::getEarnings()
{
    return this->earnings;
}

void Taxi::setTaxiStatus(bool status)
{
    this->is_booked = status;
}

void Taxi::setEarnings(int fare) 
{
    this->earnings += fare;
}

void Taxi::printTaxiDetails()
{
    std::cout << "\nTaxi NO: " << taxi_no << std::endl;
    std::cout << "Taxi Status: " << (is_booked ? "Booked" : "Available") << std::endl;
    std::cout << "Total Earnings: " << earnings << std::endl;
}

