//============================================================================
// Name        : Rational.cpp
// Author      : Nikolas X. Gamarra
// Date		   : 2/15/17
// Version     : 1
// Copyright   : -
// Description : Rational Number program
//============================================================================
#include <cstdio>
#include <iostream>

#include "Rational.h"

Rational::Rational(long long int num, long long int denom) {
	long long int n = num;
	long long int d = denom;

	simplify(n, d);

	numerator = n;
	denominator = d;
} //normal initializer

Rational::Rational(const long long int wholeNumber) {
	numerator = wholeNumber;
	denominator = 1;
} //whole number

Rational::Rational(const Rational &a) {
	long long int n = a.numerator;
	long long int d = a.denominator;

	simplify(n, d);

	numerator = n;
	denominator = d;
} //re-initialize rational

Rational::Rational() {
	numerator = 0;
	denominator = 1;
} //empty initializer

Rational::~Rational(void) {
//deconstructor
	return;
}	//	tellerQueue::~tellerQueue(void)
void Rational::simplify(long long int &num, long long int &denom) {
	if (num == 0) {
		denom = 1;
		return;
	}
	if (num == denom) {
		num = 1;
		denom = 1;
		return;
	}
	if (denom == 0)
		throw "Error: Devision by zero.";
	while (num % 2 == 0 && denom % 2 == 0) {
		num = num / 2;
		denom = denom / 2;
	}
	while (num % 3 == 0 && denom % 3 == 0) {
		num = num / 3;
		denom = denom / 3;
	}
	if (num % denom == 0 && num > denom) {
		num = num / denom;
		denom = 1;
	}
}

void Rational::print(void) {
	std::cout << this->numerator << "/" << this->denominator << " ";
}
//extra credit
Rational& Rational::operator=( Rational& r) {
	if (this == &r)
		return *this;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}
Rational Rational::operator+=( Rational & r) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int denom = b * b;
	long long int num = a * b + a * b;
	r.simplify(num, denom);
	r.numerator = num;
	r.denominator = denom;
	return r;
}
Rational Rational::operator-=( Rational & r) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int denom = b * b;
	long long int num = a * b - a * b;
	r.simplify(num, denom);
	r.numerator = num;
	r.denominator = denom;
	return r;
}
Rational Rational::operator*=( Rational & r) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int num = a * a;
	long long int denom = b * b;
	r.simplify(num, denom);
	r.denominator = denom;
	r.numerator = num;
	return r;
}

Rational Rational::operator/=( Rational & r) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int num = a / a;
	long long int denom = b / b;
	r.simplify(num, denom);
	r.denominator = denom;
	r.numerator = num;
	return r;
}

//--------------Rational and Irational Friend Operators---------------------------
std::ostream& operator<<(std::ostream& s, const Rational & r) {
	return (s << r.numerator << '/' << r.denominator);
}
std::istream& operator>>(std::istream &s, const Rational & r) {
	return (s >> r.numerator >> '/' >> r.denominator);
}

Rational operator +(const Rational &r, const Rational &s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	Rational result;
	long long int denom = b * d;
	long long int num = a * d + c * b;
	result.simplify(num, denom);
	result.denominator = denom;
	result.numerator = num;
	return result;
}	// + Operator
Rational operator -(const Rational &r, const Rational &s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;
	Rational result;
	long long int denom = b * d;
	long long int num = a * d - c * b;
	result.simplify(num, denom);
	result.denominator = denom;
	result.numerator = num;
	return result;
}	// - Operator
Rational operator *(const Rational &r, const Rational &s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;
	Rational result;
	long long int num = a * c;
	long long int denom = b * d;
	result.simplify(num, denom);
	result.denominator = denom;
	result.numerator = num;
	return result;
}	// * Operator
Rational operator /(const Rational &r, const Rational &s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;
	Rational result;
	long long int num = a * d;
	long long int denom = b * c;
	result.simplify(num, denom);
	result.denominator = denom;
	result.numerator = num;
	return result;
}	//   /Operator
int operator ==(const Rational &r, const Rational & s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	if (a * d == b * c) {
		return 1;
	} else {
		return 0;
	}
}	// == Operator

int operator !=(const Rational &r, const Rational & s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	if (a * d == b * c) {
		return 0;
	} else {
		return 1;
	}
}	//!= Operator

int operator <=(const Rational &r, const Rational & s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	if (a * d == b * c) {
		return 1;
	} else {
		if (a * d < b * c) {
			return 1;
		} else {
			return 0;
		}
	}
}	//<= Operator
int operator >=(const Rational &r, const Rational & s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	if (a * d == b * c) {
		return 1;
	} else {
		if (a * d > b * c) {
			return 1;
		} else {
			return 0;
		}
	}
}	//>= Operator
int operator >(const Rational &r, const Rational & s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	if (a * d > b * c) {
		return 1;
	} else {
		return 0;
	}
}	//>= Operator
int operator <(const Rational &r, const Rational & s) {
	long long int a = r.numerator;
	long long int b = r.denominator;
	long long int c = s.numerator;
	long long int d = s.denominator;

	if (a * d < b * c) {
		return 1;
	} else {
		return 0;
	}
}	//>= Operator
double Rational::toDouble(const Rational &r) {
	double a = r.numerator;
	double b = r.denominator;

	double result = a / b;
	return result;
}	//toDouble

