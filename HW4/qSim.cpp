//============================================================================
// Name        : qSim.cpp
// Author      : Nikolas X. Gamarra
// Version     : 1
// Copyright   : -
// Description : Simulation of bank queue
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include<stdlib.h>

#include "eventQueue.h"
#include "tellerQueue.h"
#include "qSim.h"

void printResults(qSim *v,  char const* t);
void clearData(qSim *v);
int main(int argc, char *argv[]) {
	qSim Var;
	qSim *vP = &Var;
	eventQueue E;
	if (argc < 5) { //make sure there are an ok amount of arguements
		std::cout
				<< "ERROR: Too few args.\nExpected: ./qSim #customers #tellers simulationTime averageServiceTime <seed>"
				<< std::endl;
		return 1;
	} else if (argc > 6) {
		std::cout
				<< "ERROR: Too many args.\nExpected: ./qSim #customers #tellers simulationTime averageServiceTime <seed>"
				<< std::endl;
		return 1;
	} else { //Here all arguments have been accepted: Proceed
		vP->customers = atol(argv[1]);
		vP->tellers = atol(argv[2]);
		vP->simulationTime = atol(argv[3]);
		vP->advServiceTime = atof(argv[4]);

		//check for seed
		if (argc == 6) {
			int seed = atoi(argv[5]);
			std::cout << "Warning: rand number uses seed: " << seed
					<< std::endl;
			srand(seed);
		} else {
			srand (time(NULL));}
		clearData(vP);//initialize global variables and data

		//Start of first simulation-----------------------
			//put customers in event queue with random arrival times
		for (int i = 0; i < vP->customers; i++) {

			float arrTime = vP->simulationTime * rand() / float(RAND_MAX);
			arrTime = abs(arrTime);
			E.InsertItem(arrTime, 'c', -1);
		}
		//put tellers in event queue with random service times
		for (int i = 0; i < vP->tellers; i++) {
			float serviceTime = 2 * vP->advServiceTime * rand()
					/ float(RAND_MAX);
			E.InsertItem(serviceTime, 't', 0);//add tellers all serving one q
		}
		int qNumber = vP->tellers;//save tellers and set q quant by changing tellers
		vP->tellers = 1;
		tellerQueue *Q1 = new tellerQueue[vP->tellers];

		do {		//do loop for first run
			vP->simClock = E.action(Q1, vP);//update time and perform q action
		} while ((!(vP->simClock < vP->simulationTime) ^ (E.getLength() > 0)));//end at time max or empty event queue

		//do some math for statistical output
		vP->runTime = vP->simClock;
		vP->advTime = (vP->advTime) / vP->customers;
		vP->tellers = qNumber;
		char const* r="Common";

		printResults(vP, r);//print first run results
		//start of secnod run---------------------------------------------------------------------------
		clearData(vP);//clear global variables and data
		delete[] Q1;		//delete old queue
		tellerQueue *Qs = new tellerQueue[vP->tellers];	//create queue of queues
		//put customers in event queue with random arrival times
		for (int i = 0; i < vP->customers; i++) {
			float arrTime = vP->simulationTime * rand() / float(RAND_MAX);
			arrTime = abs(arrTime);
			E.InsertItem(arrTime, 'c', -1);
		}
		//put tellers in event queue with random service times
		for (int i = 0; i < vP->tellers; i++) {
			float serviceTime = 2 * vP->advServiceTime * rand()
					/ float(RAND_MAX);
			E.InsertItem(serviceTime, 't', i);
		}
		qNumber = vP->tellers;

		do {//run simulation
			vP->simClock = E.action(Qs, vP);//one action and update time
		} while ((!(vP->simClock < vP->simulationTime) ^ (E.getLength() > 0)));//check for end condition
//do math
		vP->runTime = vP->simClock;
		vP->advTime = (vP->advTime) / (float) vP->customers;
		 r="One per teller";
		printResults(vP, r);//print results 2
		delete[] Qs;//free memory
	}

	return EXIT_SUCCESS;
}
void printResults(qSim* Varpointer, char const* t) {//helper function to print and format data

	std::cout << "-----------------------" << std::endl;
	std::cout << "-Qtype: " << t << std::endl;
	std::cout << "Total customers served: " << Varpointer->completeCustomers
			<< std::endl;
	std::cout << "Total time run: " << Varpointer->runTime << " min"
			<< std::endl;
	std::cout << "Number of tellers: " << Varpointer->tellers << std::endl;
	std::cout << "Mean time: " << Varpointer->advTime << " min" << std::endl;
	//std::cout << "Standard deviation: " << Varpointer->stdDev << std::endl;
	std::cout << "Maximum wait time: " << Varpointer->maxTime << std::endl;
	std::cout << "Teller Service time: " << Varpointer->serviceTime
			<< std::endl;
	std::cout << "Teller idle time: " << Varpointer->idleTime << std::endl;
	std::cout << "Actions performed: " << Varpointer->actions << std::endl;

}
void clearData(qSim* v) {//helper function to clear globals
	v->actions = 0;
	v->completeCustomers = 0;
	v->advTime = 0;
	v->stdDev = 0;
	v->maxTime = 0;
	v->runTime = 0;
	v->advTime = 0;
	v->serviceTime = 0;
	v->idleTime = 0;
	v->simClock = 0;
	v->actions = 0;
}
