#include <stdio.h>
#include <iostream>
#include <time.h>
#include <omp.h>
#include "elevator.h"
#include "person.h"
#include "timeSim.h"

#define NUM_THREADS 5

using namespace std;

int main()
{

	//elevator curEle;
	//curEle.run();
	//printf("elevator %d reached floor %d with %d number of passengers.\n",curEle.getElevetorID(),curEle.getFloor(),curEle.getCapacity());


	int nthreads;
	omp_set_num_threads(NUM_THREADS);

	elevator elevatorArray[NUM_THREADS];

	for(int i=0;i<5;i++){
		elevator ele;
		ele.setElevatorID(i);
		elevatorArray[i] = ele;
	}


#pragma omp parallel
	{
		for(int i=0;i<omp_get_max_threads();i++)
		{
			int id = omp_get_thread_num();
			elevator curEle = elevatorArray[id];
			while(curEle.current_passengers_on_board() >= 0){
			curEle.run();
				printf("Elevator %d reached floor %d with %d of passengers.\n",curEle.getElevetorID(),curEle.getFloor(),curEle.current_passengers_on_board());}
				//curEle.run();
		}
	}
}
