
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Board.h"
#include "Organism.h"
Board::Board(int gridSize, int ants, int doodlebugs) {
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
}
void Board::print(int gen,int gridSize) {
/*
	std::cout << std::endl << "- Generation " << gen << std::endl;
	for (int x = 0; x < gridSize; x++) {

		for (int y = 0; y < gridSize; y++) {
			if (this->Board[x][y] != NULL) {
				this->Board[x][y]->print();
			} else {
				std::cout << "*";
			}
		}
		std::cout << std::endl;

	}*/
}

