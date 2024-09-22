#include <iostream>

#ifndef LOCATION_H
#define LOCATION_H

class PointNode
{
public:
    char point;
    PointNode *next;
    PointNode *prev;

    PointNode(
        char point,
        PointNode *next = nullptr,
        PointNode *prev = nullptr)
    {
        this->point = point;
        this->next = next;
        this->prev = prev;
    }
};

class LocationList
{
public:
    PointNode *head;
    PointNode *tail;

    LocationList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void listAppend(char point);

    int calcDistance(PointNode *pickup_location, PointNode *drop_location);
};

#endif
