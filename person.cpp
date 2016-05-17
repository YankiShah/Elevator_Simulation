#include <iostream>
#include "person.h"

person::person(int dest)
{
    this->dest = dest;
}

person::person()
{
    dest = 0;
}

int person::getDestination()
{
    return dest;
}
void person::setDestination(int dest)
{
    this->dest = dest;
}
