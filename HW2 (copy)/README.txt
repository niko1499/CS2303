README for Game of Life -- Niko Gamarra 1/30/17

To Use:
type 'make' into the command line to compile all dependent files for life
type './life x y gens input.txt (y/n) (y/n)' to run the program


Sumary:
My program consists of 3 different .c files. Board, Game, and Life.
Life is the main program and sets up variables as well as invokes other functions in
other .c fiels. Life also checks for errors in user input such as the board being
smaller than the input file, ect... It also centers the input file 
int the starting array. The arrays are initialized to * to you can se the expansion
of the pervious live cells. 
 A .h file exists for each .c file in order to link them together. 
Life invokes game which consists of PlayGame and PlayOne. PlayGame loops through gens and
keeps track of how to display the generations based on info from life. 
playone sets the new array to the result of one generation and 
check all rules of the game. Board has numerous misclanious helper functions 
that make the program cleaner and keep track of the board state. For example it
prints the header which are automaticall set to the length of the board
