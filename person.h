/*
 * person.h
 *
 *  Created on: 16-May-2016
 *      Author: Yanki
 */

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class person
{
public:
    person(int dest);
    person();
    int getDestination();
    void setDestination(int dest);
private:
    int dest;
};

#endif // PERSON_H_INCLUDED
