//============================================================================
// Name        : PA6.cpp
// Author      : Nikolas X. Gamarra
// Date		   : 2/22/17
// Version     : 1
// Copyright   : -
// Description : Organism Simulation
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Organism.h"
#include "Board.h"
int width;
int main(int argc, char *argv[]) {
	int gridSize = 20;
	int doodlebugs = 5;
	int ants = 100;
	int time_steps = 2; //100
	int seed = time(NULL);
	int pause = 0;
	width = gridSize;
	std::cout << "PA6 - Nikolas Gamarra" << std::endl;

	if (argc < 1) { //make sure there are an ok amount of arguements
		//throw "ERROR: Too few args.\nExpected: './PA5 inputFile1 inputFile2(optoinal) ...'";
		std::cout
				<< "ERROR: Too many args.\nExpected: './PA6 gridSize #doodlebugs #ants #time_steps seed pause'"
				<< std::endl;
		return 1;
	} else if (argc > 8) {
		std::cout
				<< "ERROR: Too many args.\nExpected: './PA6 gridSize #doodlebugs #ants #time_steps seed pause'"
				<< std::endl;
		return 1;
	} else {		// inputs ok continue
		std::cout << "-- Starting --" << std::endl << " Grid: " << gridSize
				<< "X" << gridSize << " doodlebugs: " << doodlebugs << " ants: "
				<< ants << " steps: " << time_steps << " seed: " << seed
				<< " pause: " << pause << std::endl;

		//Board b(gridSize, ants, doodlebugs);
		//b.print(1,gridSize);

		/*int x = 0, i = 0;
		 Organism **Board;
		 Board = malloc(x * sizeof(Organism *));
		 if (Board)
		 for (i = 0; i < x; i++) {
		 Board[i] = malloc(y * sizeof(Organism));
		 if (!Board[i]) {
		 exit(-1);
		 printf("Error: malloc error 2\n");
		 }
		 }*/

		//Organism* Board[gridSize][gridSize];
		std::vector < std::vector<Organism*> > Board(gridSize);
		for (int i = 0; i < gridSize; i++) {
			Board[i] = std::vector<Organism*>(gridSize);
			for (int j = 0; j < gridSize; j++) {
				Board[i][j] = NULL;
			}
		}
		for (int x = 0; x < gridSize; x++) {
			for (int y = 0; y < gridSize; y++) {
				//std::cout << rand() << std::endl;
				if (rand() % 2 == 0) {
					if (rand() % 2 == 0 && ants > 0) {
						Board[x][y] = new Ant();
						ants--;
					} else if (doodlebugs > 0) {
						Board[x][y] = new DoodleBug();
						doodlebugs--;
					}
				} else {
					Board[x][y] = NULL;
				}

			}
		}
		int gen = 0;

		//main simulation loop
		do {

			gen++;
//---Invoke move on the objects
			for (int i = 0; i < gridSize; i++) {
				for (int j = 0; j < gridSize; j++) {
					//Board[i][j]->move();
				}
			}
//prints board. SHould go inBoard.cpp
			std::cout << std::endl << "--- Generation " << gen << std::endl;
			for (int x = 0; x < gridSize; x++) {

				for (int y = 0; y < gridSize; y++) {
					if (Board[x][y] != NULL) {
						Board[x][y]->print();
					} else {
						std::cout << "*";
					}
				}
				std::cout << std::endl;

			}

		} while (time_steps > gen);

	}
}
