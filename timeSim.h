/*
 * timeSim.h
 *
 *  Created on: 16-May-2016
 *      Author: Yanki
 */

#ifndef TIMESIM_H_INCLUDED
#define TIMESIM_H_INCLUDED

class timeSim
{
  protected:
    float p;
    float iat;
  public:
    float next(void);
    void put_interval(float t);
    float get_interval(void);
};

#endif // TIMESIM_H_INCLUDED

