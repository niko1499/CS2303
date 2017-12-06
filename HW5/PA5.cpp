//============================================================================
// Name        : PA5.cpp
// Author      : Nikolas X. Gamarra
// Date		   : 2/15/17
// Version     : 1
// Copyright   : -
// Description : Rational Number program
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <iostream>
#include <string>
#include <cstring>

#include "Rational.h"

void FileToRational(FILE *input);
int isWhitespace(char ch);
bool isNumber(const std::string& s);
void printHelper(Rational &r);
void printHelper(int num);
int main(int argc, char *argv[]) {
	char ch;
	int newLineFlag = 0;
	std::cout << "PA5 - Nikolas Gamarra" << std::endl;

	if (argc < 2) { //make sure there are an ok amount of arguements
		//throw "ERROR: Too few args.\nExpected: './PA5 inputFile1 inputFile2(optoinal) ...'";
		std::cout
				<< "ERROR: Too few args.\nExpected: './PA5 inputFile1 inputFile2(optoinal) ...'"
				<< std::endl;
		return 1;
	} else if (argc > 99) {
		std::cout
				<< "ERROR: Too many args.\nExpected: './PA5 inputFile1 inputFile2(optoinal) ...'"
				<< std::endl;
		return 1;
	} else { //Heredo { //loops through txt file and puts needed data in arrays for ease of use
		for (int i = 1; i < argc; i++) { //loop inputs
			char *inName = argv[i];
			FILE* input;
			input = fopen(inName, "r");
			if (!input) {
				std::cout << "ERROR: File not found.\ncd CS2303" << std::endl;
				return 1;
			} else { //DO THING
				Rational fractions[999];
				//Rational fractPointer[]* = &fractions;
				int current = 0;
				std::string block;
			//	std::string blockPointer* = &block;

				do { //loops through txt file and puts needed data in arrays for ease of use
					ch = fgetc(input);
					if (!isWhitespace(ch) || newLineFlag) { //put non white chars in a tem array
						if (block == "\n")
							block.clear();
						block += ch;
						newLineFlag = 0;
					} else { //white space has been hit
						if ((block.find("/") != std::string::npos)
								&& block.length() > 1) { //is a rational
							std::string num, denom;
							char delim('/');
							int de = block.find(delim);
							num = block.substr(0, de);
							denom = block.substr(de + 1);
							int n = atoi(num.c_str());
							int d = atoi(denom.c_str());
							Rational r(n, d);
							fractions[current] = r;

							std::cout << fractions[current].numerator << "/"
									<< fractions[current].denominator << " ";
							current++;
							block.clear();
						} else {						//is number or symbol
							if (isNumber(block)) {				//is a number

								int n = atoi(block.c_str());
								if (n == 0) {
									Rational r;
									fractions[current] = r;
									r.print();
									current++;
									block.clear();
								} else {
									Rational r(n);
									fractions[current] = r;
									r.print();
									current++;
									block.clear();
								}
							} else {							//is operator
								std::cout << block << "";
								newLineFlag = 1;

								if (block == "+") {
									Rational r = fractions[current - 2]
											+ fractions[current - 1];
									fractions[current] = r;
									current++;
									printHelper(r);
								} else if (block == "-") {
									Rational r = fractions[current - 2]
											- fractions[current - 1];
									fractions[current] = r;
									current++;
									printHelper(r);
								} else if (block == "/") {
									Rational r = fractions[current - 2]
											/ fractions[current - 1];
									fractions[current] = r;
									current++;
									printHelper(r);
								} else if (block == "*") {
									Rational r = fractions[current - 2]
											* fractions[current - 1];
									fractions[current] = r;
									current++;
									printHelper(r);
								} else if (block == "==") {
									int r = fractions[current - 2]
											== fractions[current - 1];
									printHelper(r);
								} else if (block == "!=") {
									int r = fractions[current - 2]
											!= fractions[current - 1];
									printHelper(r);
								} else if (block == "<") {
									int r = fractions[current - 2]
											< fractions[current - 1];
									printHelper(r);
								} else if (block == ">") {
									int r = fractions[current - 2]
											> fractions[current - 1];
									printHelper(r);
								} else if (block == ">=") {
									int r = fractions[current - 2]
											>= fractions[current - 1];
									printHelper(r);
								} else if (block == "<=") {
									int r = fractions[current - 2]
											<= fractions[current - 1];
									printHelper(r);
								} else if (block == "=") {		//Extra credit
									fractions[current] = fractions[current - 1];
									printHelper(fractions[current-1]);
									current++;
								} else if (block == "+=") {
									fractions[current] +=
											fractions[current - 1];
									printHelper(fractions[current-1]);
									current++;
								} else if (block == "-=") {
									fractions[current] -=
											fractions[current - 1];
									printHelper(fractions[current-1]);
									current++;
								} else if (block == "/=") {
									fractions[current] /=
												fractions[current - 1];
									printHelper(fractions[current-1]);
									std::cout<<std::endl;
									current++;
								} else if (block == "*=") {
									fractions[current] *=
											fractions[current - 1];
									printHelper(fractions[current-1]);
									current++;

								}
							}
							block.clear();
						}
					}
				} while (ch != EOF);
			//delete blockPointer;
			//delete fractPointer;
			}//end of
		fclose(input);
		}//end of files loop
	}
}

int isWhitespace(char ch) {
	const int types = 5;
	const char white[5] = { ' ', '\n', '\t', '\v', '\r' };
	for (int i = 0; i < types; i++) {
		if (ch == white[i])
			return 1;
		//Loop invariant: at this point the ch character will not have been the character that is currently being checked
	}
	return 0;
}		//end of isWhitespace

bool isNumber(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}
void printHelper(Rational &r) {
	std::cout << ": ";
	r.print();
	double x = r.toDouble(r);
	std::cout << " (double " << x << ")" << std::endl;
}
void printHelper(int num) {
	std::cout << ": ";
	if (num == 1) {
		std::cout << "true" << std::endl;
	} else {
		std::cout << "false" << std::endl;
	}
}
