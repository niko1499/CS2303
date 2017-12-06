//============================================================================
// Name        : Rational.h
// Author      : Nikolas X. Gamarra
// Date		   : 2/15/17
// Version     : 1
// Copyright   : -
// Description : Rational Number program
//============================================================================

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <cstdio>
#include <cstdlib>
#include <iostream>

class Rational {
public:

	Rational(const long long int num, const long long int denom);//	constructor
	Rational(const long long int wholeNumber);	//	constructor
	Rational(const Rational &a);	//	constructor
	Rational();	//	constructor

	~Rational();	//destructor

	double toDouble(const Rational &a);
	void print(void);
	long long int numerator;
	long long int denominator;

	//extra credit
	Rational& operator=( Rational& r);
	Rational operator+=( Rational & r);
	Rational operator-=( Rational & r);
	Rational operator*=( Rational & r);
	Rational operator/=( Rational & r);

	void simplify(long long int &num, long long int &denom);
private:

};

std::ostream& operator<<(std::ostream &s, Rational & r);
std::istream& operator>>(std::istream &s, Rational & r);

int operator==(const Rational & r, const Rational & s);
int operator!=(const Rational & r, const Rational & s);
int operator<(const Rational & r, const Rational & s);
int operator<=(const Rational & r, const Rational & s);
int operator>(const Rational & r, const Rational & s);
int operator>=(const Rational & r, const Rational & s);
Rational operator+(const Rational & r, const Rational & s);
Rational operator-(const Rational & r, const Rational & s);
Rational operator*(const Rational & r, const Rational & s);
Rational operator/(const Rational & r, const Rational & s);


#endif /* RATIONAL_H_ */
