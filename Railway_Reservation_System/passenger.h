#include <bits/stdc++.h>

#ifndef PASSENGER_H // Check if PASSENGER_H is not defined
#define PASSENGER_H // Define PASSENGER_H

class Passenger
{
private:
    std::string passenger_id;
    std::string name;
    int age;
    char gender;
    char berth_preference;

public:
    Passenger()
    {
        passenger_id = "";
        name = "";
        age = 0;
        gender = ' ';
        berth_preference = ' ';
    }

    // Setter Functions
    void setPassengerId(int count);
    void setName(std::string name);
    void setAge(int age);
    void setGender(char gender);
    void setBerthPreference(char berth_preference);

    // Getter Functions
    std::string getPassengerId();
    std::string getName();
    int getAge();
    char getGender();
    char getBerthPreference();
};

#endif // PASSENGER_H