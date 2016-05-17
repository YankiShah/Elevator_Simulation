/*
 * elevator.h
 *
 *  Created on: 16-May-2016
 *      Author: Yanki
 */

#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#include "timeSim.h"
#include "person.h"
#include "enums.h"
#include <list>

class elevator
{
public:
	elevator();
	int getFloor();
	void setFloor(int floorNum);

	int getElevetorID();
	void setElevatorID(int ID);

	double getSpeed();
	void setSpeed(double speed);

	bool openDoor();
	void setDoor(bool status);
	bool closeDoor();

	int getCapacity();
	void setCapacity(int cap);

    unsigned short current_direction();
    unsigned short current_state();

    int current_passengers_on_board();

    void run();

private:
	int floorNum;
	int elevatorID;
	double speed;
	int capacity;
	int personCount;
	bool doorStatus;
	unsigned short direction;
	unsigned short state;
	timeSim interval;
    person *persons[MAX_PASSENGERS];
};

#endif /* ELEVATOR_H_ */
