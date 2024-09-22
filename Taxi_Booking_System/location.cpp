#include <iostream>
#include "location.h"

void LocationList::listAppend(char point)
{
    PointNode *node = new PointNode(point);

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

int LocationList::calcDistance(PointNode* pickup_location, PointNode* drop_location)
{
    int distance = 0;

    PointNode *node = pickup_location;
    while (node != drop_location)
    {
        distance++;
        if (pickup_location->point < drop_location->point)
        {
            node = node->next;
        }
        else
        {
            node = node->prev;
        }
    }

    return distance;
}