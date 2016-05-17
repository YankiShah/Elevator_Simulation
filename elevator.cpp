/*
 * elevator.cpp
 *
 *  Created on: 16-May-2016
 *      Author: Yanki
 */

#include "enums.h"
#include "elevator.h"
#include <iostream>
#include <stdio.h>

elevator::elevator(){
    direction = UP_DIRECTION;
    state = IDLE_STATE;
    personCount = 0;
	floorNum = LOBBY_FLOOR;
	elevatorID = 0;
	speed = 0.0f;
	capacity = MAX_PASSENGERS;
	doorStatus = false;
    interval.put_interval((MAX_FLOORS-1));

    for(int i=0;i<MAX_PASSENGERS;i++)
    {
        persons[i] = NULL;
    }
}

    void elevator::run()
    {
        unsigned short destination;
        short done;
        double duration = 0;

        switch(state)
        {
        case IDLE_STATE:
            state = LOAD_STATE;
            if(direction == DOWN_DIRECTION)
            {
                direction = UP_DIRECTION;
                duration += TURN_TIME;
            }
            std::cout << "state idle: \n";
            break;

        case LOAD_STATE:
            personCount = 0;
            for(int i=0;i<MAX_PASSENGERS;i++)
            {
                done = false;
                while(!done)
                {
                    destination = (unsigned short)interval.next();
                    if((destination>0) && (destination < MAX_FLOORS))
                    {
                        done = true;
                    }
                }
                persons[i] = new person(destination);
                personCount++;
                duration+=LOAD_TIME;
            }
            state = UP_STATE;
            std::cout << "state load: \n";
            break;

            //yanki
        case UP_STATE:

        				floorNum++;
        				duration+=FLOOR_TIME;
        				for(int i=0;i<MAX_PASSENGERS;i++)
        				{
        					if(persons[i]->getDestination() == floorNum)
        							state= STOP_STATE;
        				}

        				break;
        case STOP_STATE:
            state = UNLOAD_STATE;
            duration+=STOP_TIME;
            std::cout << "state stop: \n";

            break;

        case UNLOAD_STATE:
            for(int i =0;i<MAX_PASSENGERS;i++)
            {
                if(persons[i]->getDestination() == floorNum)
                {
                    duration+=LOAD_TIME;
                    personCount--;
                }
            }
            if(personCount>0)
            {
                state=UP_STATE;
            }
            else
            {
                for(int i=0;i<MAX_PASSENGERS;i++)
                {
                    delete persons[i];
                    persons[i]=NULL;
                }
                state = DOWN_STATE;
                duration += TURN_TIME;
            }
            std::cout << "state unload: \n";

            break;

        case DOWN_STATE:
            direction=DOWN_DIRECTION;
            floorNum--;
            duration+=FLOOR_TIME;
            if(floorNum == LOBBY_FLOOR)
                state=IDLE_STATE;
            std::cout << "state downstate : \n";
            break;

        default:
        	state=this->state;
        	std::cout << "state default : \n";

            break;
        }
    }

	int elevator::getFloor(){
		return floorNum;
	}
	void elevator::setFloor(int floorNum){
		this->floorNum = floorNum;
	}

	int elevator::getElevetorID(){
		return elevatorID;
	}

	void elevator::setElevatorID(int ID){
		elevatorID = ID;
	}

	double elevator::getSpeed(){
		return speed;
	}

	void elevator::setSpeed(double speed){
		this->speed = speed;
	}

	bool elevator::openDoor(){
		return doorStatus;
	}

	void elevator::setDoor(bool status){
		doorStatus = status;
	}

	bool elevator::closeDoor(){
		return doorStatus;
	}

	int elevator::getCapacity(){
		return capacity;
	}

	void elevator::setCapacity(int cap){
		capacity = cap;
	}

	int elevator::current_passengers_on_board()
	{
	  return personCount;
	}
