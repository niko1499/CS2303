# Make file for BinaryTree Assignment
# WRITTEN BY: Nikolas Gamarra (nxgamarra@wpi.edu), 1/31/17
#
# This makefile is used as follows to regenerate files for the PA3 program:
#   make tree.o   --  Regenerates tree.o by compiling
#   make seed.o   --  Regenerates seed.o by compiling
#   make PA3      --  Regenerates the executable Game file by compiling
#   make          --  Same as "make PA3"
#

CFLAGS = -g

PA3: tree.o seed.o
	gcc $(CFLAGS) -Wall tree.o seed.o -o PA3

tree.o: tree.h tree.c 
	gcc $(CFLAGS) -Wall  -c tree.c -o tree.o

seed.o: tree.h tree.c seed.c
	gcc $(CFLAGS) -Wall  -c seed.c -o seed.o

clean:
	rm -f tree.o seed.o PA3

all: PA3


