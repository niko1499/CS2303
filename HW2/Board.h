/*
 * Board.h
 *
 *  Created on: Jan 29, 2017
 *      Author: ngamarra
 */

#ifndef BOARD_H
#define BOARD_H

void PrintBoard(int width, int height, char **New);
void PrintGenHeader(int width,int gen);
int BoardsEqual(int width, int height, char **New, char **Old);
int allDead(int x, int y,char **array);
void ZeroBoard(int x, int y ,char **Board);
void CopyBoard(int width,int height,char **Cloned,char **Copy);
int EmptyCell(int x, int y,char **Array);
#endif /* BOARD_H_ */