#include <bits/stdc++.h>
#include "passenger.h"

/*  Setter Functions  */

void Passenger::setPassengerId(int count)
{
    this->passenger_id = std::to_string(count) + this->berth_preference;
}

void Passenger::setName(std::string name)
{
    this->name = name;
}

void Passenger::setAge(int age)
{
    this->age = age;
}

void Passenger::setGender(char gender)
{
    this->gender = gender;
}

void Passenger::setBerthPreference(char berth_preference)
{
    this->berth_preference = berth_preference;
}

/*  Getter Functions  */

std::string Passenger::getPassengerId()
{
    return this->passenger_id;
}

std::string Passenger::getName()
{
    return this->name;
}

int Passenger::getAge()
{
    return this->age;
}

char Passenger::getGender()
{
    return this->gender;
}

char Passenger::getBerthPreference()
{
    return this->berth_preference;
}