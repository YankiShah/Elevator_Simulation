#include "timeSim.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

float timeSim::next()
{
  double dbl_rand,max_rand;

  do
  {
    dbl_rand = (double)rand();
    max_rand = (double)RAND_MAX;

    p = float (iat*-log10((dbl_rand)/(max_rand+1)));
  } while (!p);

  return p;
}

void timeSim::put_interval(float t)
{
  iat = t;
  // set random seed based on system time
  srand((unsigned)time(NULL));
}

float timeSim::get_interval(void)
{
  return iat;
}
