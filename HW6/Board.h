#ifndef BOARD_H_
#define BOARD_H_

#include <cstdio>
#include <cstdlib>

#include "Organism.h"
class Board {
public:

	Board(int width, int ants, int doodlebugs);	//	constructor
	~Board();	//	destructor
	void print(int gen, int grid);

	//Organism b[20][20];
private:

	// class

};

#endif /* BOARD */

