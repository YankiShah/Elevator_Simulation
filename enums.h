/*
 * enums.h
 *
 *  Created on: 16-May-2016
 *      Author: Yanki
 */

#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

#define IDLE_STATE (0)
#define LOAD_STATE (1)
#define UP_STATE (2)
#define STOP_STATE (3)
#define UNLOAD_STATE (4)
#define DOWN_STATE (5)

#define MAX_PASSENGERS (20)

#define LOBBY_FLOOR (0)
#define TOP_FLOOR (9)
#define MAX_FLOORS (10)

#define UP_DIRECTION (1)
#define DOWN_DIRECTION (2)

// time to move on floor at the maximum speed
#define FLOOR_TIME (1.45)
// time needed to decelerate, open and close the doors, and accelerate
#define STOP_TIME (7.19)
// time needed for stopped car to change directions
#define TURN_TIME (1.0)
// mean time for 1 passenger to enter or exit the car
#define LOAD_TIME (1.0)

#endif // ENUMS_H_INCLUDED
