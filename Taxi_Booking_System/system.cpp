#include <iostream>
#include "system.h"

void System::displayTaxiDetails()
{
    for (auto it = taxis.begin(); it != taxis.end(); it++)
    {
        it->printTaxiDetails();
    }
}

void System::bookTaxi()
{
    int customer_id;
    std::cout << "Enter customer id: ";
    std::cin >> customer_id;

    char pickup_location;
    std::cout << "Enter your Pickup Location: ";
    std::cin >> pickup_location;

    char drop_location;
    std::cout << "Enter your Drop Location: ";
    std::cin >> drop_location;

    int pickup_time;
    std::cout << "Enter your Pickup Time: ";
    std::cin >> pickup_time;

    PointNode *node = this->location.head;
    PointNode *tail_node = this->location.tail;

    PointNode *pickup_point;
    PointNode *drop_point;

    while (node != tail_node)
    {
        if (node->point == pickup_location)
        {
            pickup_point = node;
        }
        if (node->point == drop_location)
        {
            drop_point = node;
        }

        node = node->next;
    }

    int distance = this->location.calcDistance(pickup_point, drop_point);
    int drop_time = pickup_time + distance;

    int taxi_no;
    for (auto it = this->taxis.begin(); it != this->taxis.end(); it++)
    {
        if (it->getTaxiStatus() == false)
        {
            taxi_no = it->getTaxiNo();
            it->setTaxiStatus(true);
            it->setEarnings(distance);
            break;
        }
    }

    Booking booking = Booking(customer_id, taxi_no, pickup_point, drop_point, pickup_time, drop_time);
    booking.printBookingDetails();

    bookings.push_back(booking);
}

void System::displayBookings()
{
    for (auto it = bookings.begin(); it != bookings.end(); it++)
    {
        it->printBookingDetails();
    }
}
