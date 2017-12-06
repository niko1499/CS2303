//============================================================================
// Name        : Organism.cpp
// Author      : Nikolas X. Gamarra
// Date		   : 2/22/17
// Version     : 1
// Copyright   : -
// Description : Organism Simulation
//============================================================================

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//namespace Org {
class Organism {
public:

	Organism() {
	}
	;	//	constructor
	virtual ~Organism() {
	}
	;	//destructor

	virtual void move(void) = 0;
	virtual void print(void)=0;
	virtual void replicate(void)=0;
	int age;
	int x,y;//my location
private:

};
//}

class Ant: public Organism {
public:
	Ant() {
	}
	;

	void move(void);
	void print(void);
	void replicate(void);
};

class DoodleBug: public Organism {
public:
	DoodleBug() {
	}
	;
	void move(void);
	void print(void);
	void replicate(void);
};

#endif /* ORGANISM_H_ */
