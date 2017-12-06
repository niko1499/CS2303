README for PA3 -- Nikolas Gamarra (2/5/17)
------------------------------------------------------------------
To compile:
Type 'make' from the command line in the project directory.
------------------------------------------------------------------
To Run:
Type './PA3 output.txt input.txt input.txt ...'

The first two arguements are required. Additional inputs are optional.
------------------------------------------------------------------
Description:
This program strips the individual words out of any number of input fils and puts them in 
a binary tree. It then creates an output file with the unique words and their relative 
frequencies listed. 
------------------------------------------------------------------
Structure:
PA3 consists of 2 .c files and one .h file
The .c files are seed. and tree.c

seed.c - contains only the main method in which it interprets the arguments presented by the 
user and makes appropriate errors or calls to helper functions located in tree.c

tree.c - contains all helper functions for tree creation, interpretation, manipulation, and 
printing tree contents to the output file.

tree.h - contains the structure for the treeItems or tree branches and definitions
for all functions in tree.c that need to be called by an external source. tree.c and seed.c 
include tree.h

Recursion in an importat topic for this assignment. The TreePrintFile works recursivly
by calling itself with it's right or left members as it works through the tree in alphabetical
order

------------------------------------------------------------------
Problems:

One major problem that set me back a long time was forgeting to have by function that
puts the .txt file into the return the said tree when done so that it could br printed
later.

Alother problem was the global variables I used to keep track of total words and 
unique words. I wanted to avoid using global variables at first but the life span of them
as non-golobal variables was too short. 
------------------------------------------------------------------
Loop Invariants:

Loop invariant: At this point the file of index i in the arguments has been added to the tree.
Loop invariant: at this point the x letters in finalWord are guarenteeded to be lower case
Loop invariant: at this point the current tree item will have been added to the file as a new line
Loop invariant: at this point the current tree item will have been added to the file as a new line
Loop invariant: at this point the ch character will not have been the character that is currently being checked

------------------------------------------------------------------
Referenced Code:
Several helper functions were borrowed or modified from other code.

TreeAdd()  -- Lecture slides on PA3
TreePrint() -- K&R Ch7

All other functions represent origional code.
