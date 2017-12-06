//Game.c --  Niko Gamarra

#include "Life.h"
#include "Board.h"
#include "Game.h"

#include <stdio.h>
#include <stdlib.h>

void PlayGame(int x, int y, int gens, char **Old, char **New, int print,
		int pause) {
	int i;
	if (gens==0||print==1) {//if zero gens print starting config
		PrintGenHeader(x, 0);
		PrintBoard(x, y, Old);
	}
	for (i = 0; i <= gens-2; i++) {//loop through generations

		PlayOne(x, y, Old, New);//makes call to play one gen

		if (print) {//print each gen
			PrintGenHeader(x, i + 1);
			PrintBoard(x, y, New);
			if (pause) {//pause between gens
				printf("Press Enter to continue 1 generation.\n");
				getchar();
			}
		}
		if (allDead(x, y, New)) {//check if all are dead.
			i = gens + 1;
			printf("All Dead.\n");
		}
		CopyBoard(x, y, New, Old);
	}
	//print last gen
	if ( gens > 0) {
		PrintGenHeader(x, i + 1);
		PrintBoard(x, y, New);
	}
}
void PlayOne(int width, int height, char **Old, char **New) {
	int xScanMin, xScanMax, yScanMin, yScanMax;
	int neighbors = 0;
	for (int x = 0; x < width; x++) {
		//check if at x edge
		if (x == 0) {
			xScanMin = 0;
		} else {
			xScanMin = -1;
		}
		if (x == width - 1) {
			xScanMax = 0;
		} else {
			xScanMax = 1;
		}
		for (int y = 0; y < height; y++) {
			//check if at y edge
			if (y == 0) {
				yScanMin = 0;
			} else {
				yScanMin = -1;
			}
			if (y == height - 1) {
				yScanMax = 0;
			} else {
				yScanMax = 1;
			}
			//Run scan of neighbors
			for (int i = xScanMin; i <= xScanMax; i++) {
				for (int j = yScanMin; j <= yScanMax; j++) {
					if (Old[x + i][y + j] == 'x') {
						neighbors++;
					}
				}
			}
			if (Old[x][y] == 'x')
				neighbors--; //subtract self from neighbors
			//printf("NE: %d\n", neighbors);
			//logic for placing new cell survival/birth/death
			if (EmptyCell(x, y, Old)) { //cell is unocupied
				if (neighbors == 3) {
					New[x][y] = 'x'; //birth
				}
			} else { //cell is ocupied
				if (neighbors == 2 || neighbors == 3) { //Survival
					New[x][y] = Old[x][y];
				} else { //death
					New[x][y] = 'o';
				}
			} //end of cell write

			neighbors = 0;
		} //y for loop
	} //x for loop

}
