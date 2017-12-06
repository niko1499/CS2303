README for PA5 -- Nikolas X. Gamarra
------------------------------------------------------------------
To compile:
Type 'make' from the command line in the project directory.
------------------------------------------------------------------
To Run:
Type './PA5 inputFile1 inputFile2(optoinal) ...'

Provided test file: 'niko_test.txt"
------------------------------------------------------------------
Description:
This program is an implementation of a rational number class. All Rational numbers 
are stored in their most simplified versions and objects of type Rational
which include a numerator and a denominator. Several Operators are customly
defined so that they work correctly as one would expect when acting on rational
numbers. The program also consists of a the PA5 class which is used to test 
Rational. It takes properly formatted inputs from a .txt file and runs them
throught the rational class. 
------------------------------------------------------------------
Structure:
PA5 consists of 2 .cpp files and 1 .h file
Rational.cpp
Defines the structure of a rational number. Redefines operators to work properly. 
Has several helper functions to print the Rational number easily
Rational.h
Header file for Rational.cpp. Lays out the classes structure and functions.
PA5.cpp
Tester class that takes formatted inputs from one or more .txt files and runs
them through their specified operations in the rational class while 
printing the results. 
------------------------------------------------------------------
Problems:
Had trouble getting whole numbers to work. Solved by clearing my
temporary string better.

With my test .txt files the program runs with no problems. Other test files
often result instack smashing but only after the program finishes.

Stack smashing has not happend with my txt files an I have not been able
to replicate or trace down the problem. 
------------------------------------------------------------------
Extra Credit:
The Extra credit operators were added and can be found in Rational.cpp.
The file niko_test.txt uses these operators. 
------------------------------------------------------------------
Results:

** Note inputs are simplified before displaying and single argument operators will print on a new line using the result of the p
previous as their second arguement.

ngamarra@CS-2303-VirtualBox:~/CS2303/HW5$ ./PA5 niko_test.txt
PA5 - Nikolas Gamarra
1/2 1/2 +: 1/1  (double 1)
-1/2 1/2 +: 0/1  (double 0)
1/1 1/3 >: true
1/2 1/4 <: false
2/1 2/1 >=: true
1/8 8/9 <=: true
1/4 1/8 -: 1/8  (double 0.125)
9/1 4/1 *: 36/1  (double 36)
1/4 1/1 *: 1/4  (double 0.25)
3/4 9/64 -: 39/64  (double 0.609375)
9/4 9/4 ==: true
9/4 9/4 !=: false
1/2 1/4 +: 3/4  (double 0.75)
2/1 *: 3/2  (double 1.5)
1/2 -: 1/1  (double 1)
1/1 ==: true
1/3 3/1 /: 1/9  (double 0.111111)
0/1 9/1 *: 0/1  (double 0)
0/1 9/1 *: 0/1  (double 0)
5246/25199 ==: false
1/2 1/2 *=: 1/4  (double 0.25)
1/2 -=: 0/1  (double 0)
11/2 +=: 11/1  (double 11)
4/3 41/2 0/1 66043/4 9048/297469 *=: 81866304/88487805961  (double 0.00092517)


ngamarra@CS-2303-VirtualBox:~/CS2303/HW5$ ./PA5 anrus_test1.txt
PA5 - Nikolas Gamarra
1/1 1/3 +: 4/3  (double 1.33333)
1/2 1/3 +: 5/6  (double 0.833333)
4/1 +: 29/6  (double 4.83333)
1/1 2/1 +: 3/1  (double 3)
1/1 +: 4/1  (double 4)
1/2 +: 9/2  (double 4.5)
1/2 +: 5/1  (double 5)
4/1 2/1 -: 2/1  (double 2)
-11/2 -: 3/2  (double 1.5)
3/4 -: 3/4  (double 0.75)
1/28019 1/102523 +: 130542/2872591937  (double 4.5444e-05)
1/2 9/2 +: 5/1  (double 5)
3/4 -: 17/4  (double 4.25)
100/1 +: 417/4  (double 104.25)
41/152 +: 15887/152  (double 104.52)
4/1 4/1 *: 16/1  (double 16)
1/2 2/3 *: 1/3  (double 0.333333)
1/-2 6/67 *: 3/-67  (double -0.0447761)
10/1 *: 30/-67  (double -0.447761)
-51/7 *: -1530/-469  (double 3.26226)
8/1 4/1 /: 2/1  (double 2)
13/16 -34/-17 /: -221/-544  (double 0.40625)
5/6 41/1 *: 205/6  (double 34.1667)
89/99 /: 6765/178  (double 38.0056)
12/23 67/1 +: 1553/23  (double 67.5217)
41/51 *: 63673/1173  (double 54.2822)
56/1 /: 63673/65688  (double 0.969325)
-5/50 -: 1756045/1642200  (double 1.06932)
4/1 5/1 <: true
1/2 3/4 <: true
3/7 4/-5 <: true
91/1 76/1 >: true
9/1 7/6 >: true
-4/5 -2/3 >: false
1/2 1/2 ==: true
1/8 1/9 ==: false
1/2 1/3 *: 1/6  (double 0.166667)
5/6 ==: false
1/2 1/2 !=: false
1/8 1/9 !=: true
1/2 1/3 *: 1/6  (double 0.166667)
5/6 !=: true
1/1 1/1 <=: true
4/5 1/1 <=: true
1/3 1/4 <=: false
1/1 1/1 >=: true
4/5 1/1 >=: false
1/3 1/4 >=: true
*** stack smashing detected ***: ./PA5 terminated
Aborted (core dumped)

------------------------------------------------------------------
Referenced Code:
None


 
