#include <iostream>
#include "booking.h"

int Booking::booking_counter = 0;

void Booking::printBookingDetails()
{
    std::cout << "\nBooking ID : " << this->booking_id << std::endl;
    std::cout << "Customer ID : " << this->customer_id << std::endl;
    std::cout << "Taxi NO : " << this->taxi_no << std::endl;
    std::cout << "Pickup Point : " << this->pickup_location->point << std::endl;
    std::cout << "Drop Point : " << this->drop_location->point << std::endl;
    std::cout << "Pickup Time: " << this->pickup_time << std::endl;
    std::cout << "Drop Time: " << this->drop_time << std::endl;
}
