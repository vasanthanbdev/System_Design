#include <bits/stdc++.h>
#include "ticket.h"

bool Ticket::checkAvailableTickets()
{
    int total = this->confirmed + this->rac + this->waiting;
    if (total < total_tickets)
        return true;
    return false;
}

void Ticket::printAvailableTickets()
{
    std::cout << "\n----Available Tickets------" << std::endl;
    std::cout << "Lower Berths Tickets       : " << total_lower - this->lower << std::endl;
    std::cout << "Middle Berths Tickets      : " << total_middle - this->middle << std::endl;
    std::cout << "Upper Berths Tickets       : " << total_upper - this->upper << std::endl;
    std::cout << "RAC Tickets                : " << total_rac - this->rac << std::endl;
    std::cout << "Waiting List Tickets       : " << total_waiting - this->waiting << std::endl;
}

void Ticket::bookTickets(
    Passenger &passenger,
    std::deque<std::pair<std::string, Passenger>> &confirmed_tickets)
{
    if (!checkAvailableTickets())
    {
        std::cout << "### No Tickets Available! ###" << std::endl;
        return;
    }

    std::string name;
    std::cout << "Enter passenger's Name: ";
    std::cin >> name;
    passenger.setName(name);

    int age;
    std::cout << "Enter passenger's Age: ";
    std::cin >> age;
    passenger.setAge(age);

    char gender;
    std::cout << "Enter passenger's Gender (M/F): ";
    std::cin >> gender;
    passenger.setGender(gender);

    char berth_preference;
    std::cout << "Enter passenger's Birth Preference (L/M/U): ";
    std::cin >> berth_preference;

    allocateTickets(passenger, berth_preference);

    confirmed_tickets.push_back({passenger.getPassengerId(), passenger});

    std::cout << "##### Ticket Booked Successfully! #####" << std::endl;
}

void Ticket::allocateTickets(Passenger &passenger, char &berth_preference)
{
    switch (berth_preference)
    {
    case 'L':
        if (this->lower < total_lower)
        {
            this->lower++;
            this->confirmed++;
            passenger.setBerthPreference(berth_preference);
            passenger.setPassengerId(this->lower);
        }
        else if (this->middle < total_middle)
        {
            this->middle++;
            this->confirmed++;
            passenger.setBerthPreference('M');
            passenger.setPassengerId(this->middle);
        }
        else if (this->upper < total_upper)
        {
            this->upper++;
            this->confirmed++;
            passenger.setBerthPreference('U');
            passenger.setPassengerId(this->upper);
        }
        else if (this->rac < total_rac)
        {
            this->rac++;
            passenger.setBerthPreference('R');
            passenger.setPassengerId(this->rac);
        }
        else
        {
            this->waiting++;
            passenger.setBerthPreference('W');
            passenger.setPassengerId(this->waiting);
        }
        break;

    case 'M':
        if (this->middle < total_middle)
        {
            this->middle++;
            this->confirmed++;
            passenger.setBerthPreference('M');
            passenger.setPassengerId(this->middle);
        }
        else if (this->lower < total_lower)
        {
            this->lower++;
            this->confirmed++;
            passenger.setBerthPreference(berth_preference);
            passenger.setPassengerId(this->lower);
        }
        else if (this->upper < total_upper)
        {
            this->upper++;
            this->confirmed++;
            passenger.setBerthPreference('U');
            passenger.setPassengerId(this->upper);
        }
        else if (this->rac < total_rac)
        {
            this->rac++;
            passenger.setBerthPreference('R');
            passenger.setPassengerId(this->rac);
        }
        else
        {
            this->waiting++;
            passenger.setBerthPreference('W');
            passenger.setPassengerId(this->waiting);
        }
        break;

    case 'U':
        if (this->upper < total_upper)
        {
            this->upper++;
            this->confirmed++;
            passenger.setBerthPreference('U');
            passenger.setPassengerId(this->upper);
        }
        else if (this->lower < total_lower)
        {
            this->lower++;
            this->confirmed++;
            passenger.setBerthPreference(berth_preference);
            passenger.setPassengerId(this->lower);
        }
        else if (this->middle < total_middle)
        {
            this->middle++;
            this->confirmed++;
            passenger.setBerthPreference('M');
            passenger.setPassengerId(this->middle);
        }
        else if (this->rac < total_rac)
        {
            this->rac++;
            passenger.setBerthPreference('R');
            passenger.setPassengerId(this->rac);
        }
        else
        {
            this->waiting++;
            passenger.setBerthPreference('W');
            passenger.setPassengerId(this->waiting);
        }
        break;
    }
}

void Ticket::printBookedTickets(std::deque<std::pair<std::string, Passenger>> confirmed_tickets)
{
    while (!confirmed_tickets.empty())
    {
        std::pair it = confirmed_tickets.front();
        Passenger passenger = it.second;

        std::cout << std::setw(10) << std::left << "\nName       : " << passenger.getName() << std::endl;
        std::cout << std::setw(10) << std::left << "Ticket Id  : " << passenger.getPassengerId() << std::endl;
        std::cout << std::setw(10) << std::left << "Age        : " << passenger.getAge() << std::endl;
        std::cout << std::setw(10) << std::left << "Gender     : " << passenger.getGender() << std::endl;
        std::cout << std::setw(10) << std::left << "Berth      : " << passenger.getBerthPreference() << std::endl;

        confirmed_tickets.pop_front();
        std::cout << "---------------------------" << std::endl;
    }
}

void Ticket::cancelTickets(std::deque<std::pair<std::string, Passenger>> &confirmed_tickets)
{
    while (true)
    {
        std::string ticket_id;
        std::cout << "\nEnter your Ticket Id: ";
        std::cin >> ticket_id;

        for (auto it = confirmed_tickets.begin(); it != confirmed_tickets.end(); it++)
        {
            if (it->first == ticket_id)
            {
                Passenger passenger = it->second;

                std::cout << std::setw(10) << std::left << "\nName       : " << passenger.getName() << std::endl;
                std::cout << std::setw(10) << std::left << "Ticket Id  : " << passenger.getPassengerId() << std::endl;
                std::cout << std::setw(10) << std::left << "Age        : " << passenger.getAge() << std::endl;
                std::cout << std::setw(10) << std::left << "Gender     : " << passenger.getGender() << std::endl;
                std::cout << std::setw(10) << std::left << "Berth      : " << passenger.getBerthPreference() << std::endl;

                confirmed_tickets.erase(it);
                decreamentTickets(ticket_id);
                reorderRacTickets(confirmed_tickets, ticket_id);
                reorderWaitingTickets(confirmed_tickets, ticket_id);

                std::cout << "\nYour Ticket cancelled Successfully!" << std::endl;
                return;
            }
        }

        std::cout << "\nTicket Not Found! Please enter a valid Ticket ID";
    }
}

void Ticket::decreamentTickets(std::string ticket_id)
{
    char berth = ticket_id[ticket_id.length() - 1];
    switch (berth)
    {
    case 'L':
        this->lower--;
        this->confirmed--;
        break;

    case 'M':
        this->middle--;
        this->confirmed--;
        break;

    case 'U':
        this->upper--;
        this->confirmed--;
        break;

    case 'R':
        this->rac--;
        break;

    case 'W':
        this->waiting--;
        break;
    }
}

void Ticket::reorderRacTickets(
    std::deque<std::pair<std::string, Passenger>> &confirmed_tickets,
    std::string ticket_id)
{
    Passenger temp, passenger;
    for (auto it = confirmed_tickets.begin(); it != confirmed_tickets.end(); it++)
    {
        if (it->first[(it->first).length() - 1] == 'R')
        {
            temp = it->second;
            confirmed_tickets.erase(it);
            this->rac--;
            break;
        }
    }

    passenger.setName(temp.getName());
    passenger.setAge(temp.getAge());
    passenger.setGender(temp.getGender());
    passenger.setBerthPreference(temp.getBerthPreference());

    char berth = ticket_id[ticket_id.length() - 1];
    if (berth == 'L')
        passenger.setPassengerId(++this->lower);
    else if (berth == 'M')
        passenger.setPassengerId(++this->middle);
    else
        passenger.setPassengerId(++this->upper);

    confirmed_tickets.push_back({passenger.getPassengerId(), passenger});
    this->confirmed++;
}

void Ticket::reorderWaitingTickets(
    std::deque<std::pair<std::string, Passenger>> &confirmed_tickets,
    std::string ticket_id)
{
    Passenger temp, passenger;
    for (auto it = confirmed_tickets.begin(); it != confirmed_tickets.end(); it++)
    {
        if (it->first[(it->first).length() - 1] == 'W')
        {
            temp = it->second;
            confirmed_tickets.erase(it);
            this->waiting--;
            break;
        }
    }

    passenger.setName(temp.getName());
    passenger.setAge(temp.getAge());
    passenger.setGender(temp.getGender());
    passenger.setBerthPreference(temp.getBerthPreference());

    char berth = ticket_id[ticket_id.length() - 1];
    if (berth == 'L')
        passenger.setPassengerId(++this->lower);
    else if (berth == 'M')
        passenger.setPassengerId(++this->middle);
    else
        passenger.setPassengerId(++this->upper);

    confirmed_tickets.push_back({passenger.getPassengerId(), passenger});
    this->confirmed++;
}
