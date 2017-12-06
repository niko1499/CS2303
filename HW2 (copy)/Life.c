//life.c -- Niko Gamarra
#include <stdio.h>
#include <stdlib.h>
#include "Life.h"
#include "Game.h"
#include "Board.h"

int main(int argc, char * argv[]) {
	printf("---------- GAME OF LIFE ----------\n");
	printf("--Niko Gamarra\n\n");
	int print = 0, pause = 0;
	char ch1 = '0';
	int k = 0, charWidth = 0, lines = 0;
	char rawCharacters[99];
	if (argc < 5) {
		printf("ERROR: Too few args.\n");
	} else if (argc > 7) {
		printf("ERROR: Too many args.\n");
	} else {
		//set up variables
		int x, y, gens;
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		gens = atoi(argv[3]);
		if (argc > 5) {
			char temp = *argv[5];
			if (temp == 'y' || temp == 'Y')
				print = 1;
			if (argc > 6) {
				temp = *argv[6];
				if (temp == 'y' || temp == 'Y')
					pause = 1;
			}
		}
		//setup pointer arrays for boards
		char **Old;
		unsigned int i;
		Old = malloc(x * sizeof(char *));
		if (Old)
			for (i = 0; i < x; i++) {
				Old[i] = malloc(y * sizeof(char));
				if (!Old[i]) {
					exit(-1);
					printf("Error: malloc error 1\n");
				}
			}

		char **New;
		New = malloc(x * sizeof(char *));
		if (New)
			for (i = 0; i < x; i++) {
				New[i] = malloc(y * sizeof(char));
				if (!New[i]) {
					exit(-1);
					printf("Error: malloc error 2\n");
				}
			}
//initialize arrays
		ZeroBoard(x, y, New);
		ZeroBoard(x, y, Old);

		//open the file
		FILE *input;
		input = (fopen(argv[4], "r"));
		if (!input) {
			printf("ERROR: File not found.");
		} else { // put txt into old

			for (int r = 0; r < 99; r++) {
				rawCharacters[r] = '*';
			}
			int u = 1;
			do { //loops through txt file and puts needed data in 1d array for easy use
				ch1 = fgetc(input);
				if (ch1 == 'o' || ch1 == 'x') {
					rawCharacters[u] = ch1;
					u++;
					charWidth++;
				}
				if (ch1 == '\n') {
					rawCharacters[u] = 'n';
					u++;
					lines++;
				}
				k++;
			} while (ch1 != EOF);
			lines--;
			charWidth = charWidth / lines;

			lines = lines + 4;
			charWidth = charWidth + 4;

			char **tempArray; //temporayry small 2d array for centering
			unsigned int h;
			tempArray = malloc(charWidth * sizeof(char *));
			if (tempArray)
				for (h = 0; h < charWidth; h++) {
					tempArray[h] = malloc(lines * sizeof(char));
					if (!tempArray[h]) {
						exit(-1);
						printf("Error: malloc error 1\n");
					}
				}
			k = 1;
			int q = 2, z = 2;
			ZeroBoard(charWidth, lines, tempArray);
			do { //loops through 1d array and puts it into 2d array
				if (rawCharacters[k] == 'x' || rawCharacters[k] == 'o'
						|| rawCharacters[k] == ' ') {
					if (rawCharacters[k] == ' ') {
						tempArray[q][z] = '*';
					} else {
						tempArray[q][z] = rawCharacters[k];
					}
					q++;
				} else {
					q = 2;
					if (rawCharacters[k] == 'n')
						z++;
				}
				k++;
			} while (rawCharacters[k] != EOF);

			for (int i = 0; i < charWidth; i++) { //places small 2d array in 1st board
				for (int j = 0; j < lines; j++) {
					Old[((x / 2) - (charWidth / 2)) + i][((y / 2) - (lines / 2))
							+ j] = tempArray[i][j];
				}
			}
		}
		CopyBoard(x, y, Old, New);

		if (charWidth <= x && lines <= y) { //call the game if ok
			PlayGame(x, y, gens, Old, New, print, pause);
		} else {
			printf("ERROR: file too large for board size.\n");
		}
	}
} //end of main

