/*
 * qSim.h
 * Nikolas X. Gamarra
 * 2/11/17
 * holds global variables
 */

#ifndef QSIM_H_
#define QSIM_H_

#include <cstdio>
#include <cstdlib>

class qSim {
public:
	int tellers;
	int customers;
	float runTime;
	float advTime;
	float stdDev;
	float maxTime;
	float advServiceTime;
	float serviceTime;
	float idleTime;
	float simClock;
	float simulationTime;
	int actions;
	int completeCustomers;

private:

};

#endif /* QSIM_H_ */
