README for PA5 -- Nikolas X. Gamarra
------------------------------------------------------------------
To compile:
Type 'make' from the command line in the project directory.
------------------------------------------------------------------
To Run:
Type './PA6 gridSize #doodlebugs #ants #time_steps seed pause'

all arguements optional. default values provided
------------------------------------------------------------------
Description:
This program is an implementation of a simulation of ants and doodle
bugs. These organisms exists on a grid and are each implementattions
of an abstaract organims class. Bugs eat ants. Bugs starve
 if they done eat ants. Ants breed if they live long enough.
 
------------------------------------------------------------------
Structure:
PA6 consists of 3 .cpp files and 2 .h file
Organism.cpp
Abstract class that defines structure of ants and bugs
Organism.h
Header file for Organism.cpp. Lays out the classes structure and functions.
PA6.cpp
Location of the main loop. Interprets user input and makes appropritae calls to Organism.
Board.cpp
Game board grid as an array and helper functions
Board.h
Header file for Board.cpp. Lays out the classes structure and functions.
 
------------------------------------------------------------------
Problems:
I ran out of time and was not able to fully implement this a
assignment. The program submitted will compile and run.
It only creates a grid of the specified size with the 
specified number or organisms. The organisms are 
placed randomly based on the provided seed or randome one.

The structures for all the other parts of the program(like 
movinge the specific organism) are 
layed out where they would belong based
on the assignement and correct usage of abstract
classes but not implemented. 

------------------------------------------------------------------
Extra Credit:
 N/A
------------------------------------------------------------------
Results:

output of random grid of bugs and ants

PA6 - Nikolas Gamarra
-- Starting --
 Grid: 20X20 doodlebugs: 5 ants: 100 steps: 2 seed: 1488470048 pause: 0

- Generation 1
*x***o**xx*ooxx*o***
*o*********o***o*o**
*********o**oo***oo*
oo**o****o*o********
***********o****o***
*****o**oo******o***
*******o***o***ooo**
*o****o**o*o***o*o**
oo****o*oo*oo*oo**o*
****o*******o*oooo**
**o**o*************o
oo**ooo***o*oo***o*o
***o*o*******o*oo*o*
ooo****o*o*o*******o
*o***o*o*oo****o****
************o****o**
*o**o*o********oo*o*
ooooo*o******o*o****
***o****************
********************

------------------------------------------------------------------
Referenced Code:
None


 
