# Make file for GameOfLife
# WRITTEN BY: Nikolas Gamarra (nxgamarra@wpi.edu), 1/27/17
#
# This makefile is used as follows to regenerate files for the sinewave program:
#   make Life.o   --  Regenerates Life.o by compiling
#   make Game.o   --  Regenerates Game.o by compiling
#   make Game     --  Regenerates the executable Game file by compiling
#   make              --  Same as "make Game"
#

CFLAGS = -g

life: Life.o Game.o Board.o
	gcc $(CFLAGS) -Wall Game.o Life.o Board.o -o life 

Life.o: Life.h Life.c Game.c
	gcc $(CFLAGS) -Wall  -c Life.c -o Life.o

Game.o: Life.h Board.h Game.c
	gcc $(CFLAGS) -Wall  -c Game.c -o Game.o

Board.o: Life.h Board.c
	gcc $(CFLAGS) -Wall -c Board.c -o Board.o

clean:
	rm -f Game.o Life.o Game.o Board.o Life 

all: life


