// Lab 5.3.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Fraction {
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};
Fraction::Fraction(int numerator, int denominator) : numerator(numerator),
denominator(denominator) {
	if (denominator == 0) {
		denominator = 1;
	}
}
string Fraction::toString() {
	string result = (numerator * denominator > 0) ? "" : "-";
	int wholes = abs(numerator) / abs(denominator);
	int parts = abs(numerator) % abs(denominator);
	if (parts == 0 && wholes == 0) {
		result = '0';
	}
	else {
		if (wholes > 0) {
			result += std::to_string(wholes);
		}
		if (wholes > 0 && parts > 0) {
			result += ' ';
		}
		if (parts > 0) {
			result += std::to_string(abs(parts)) + '/' +
				std::to_string(abs(denominator));
		}
	}
	return result;
}
double Fraction::toDouble() {
	return double(numerator) / denominator;
}
int main(void) {
	int num, den;
	string input = "";
	getline(cin, input);
	if (2 == sscanf_s(input.c_str(), "%d / %d", &num, &den)) {
		Fraction fraction(num, den);
		cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	}
	else {
		cout << "Unrecognized input format" << endl;
	}
	system("pause");
	return 0;
}