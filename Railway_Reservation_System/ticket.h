#include <bits/stdc++.h>
#include "passenger.h"

#ifndef TICKET_H // Check if TICKET_H is not defined
#define TICKET_H // Define TICKET_H

#define total_tickets 10
#define total_confirmed 0
#define total_lower 2
#define total_upper 2
#define total_middle 2
#define total_rac 2
#define total_waiting 2

class Ticket
{
private:
    int confirmed, rac, waiting, lower, middle, upper;

public:
    Ticket()
    {
        confirmed = 0;
        rac = 0;
        waiting = 0;
        lower = 0;
        middle = 0;
        upper = 0;
    }

    bool checkAvailableTickets();
    void printAvailableTickets();
    void bookTickets(Passenger &passenger, std::deque<std::pair<std::string, Passenger>> &confirmed_tickets);
    void allocateTickets(Passenger &passenger, char &berth_preference);
    void printBookedTickets(std::deque<std::pair<std::string, Passenger>> confirmed_tickets);
    void cancelTickets(std::deque<std::pair<std::string, Passenger>> &confirmed_tickets);
    void decreamentTickets(std::string ticket_id);
    void reorderRacTickets(std::deque<std::pair<std::string, Passenger>> &confirmed, std::string ticket_id);
    void reorderWaitingTickets(std::deque<std::pair<std::string, Passenger>> &confirmed, std::string ticket_id);
};

#endif // TICKET_H