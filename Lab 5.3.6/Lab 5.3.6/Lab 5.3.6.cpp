// Lab 5.3.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

// Fraction class that converts a fraction to a string and a denominator
class Fraction {
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
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

bool isValid(string input, int num, int den) {
	if (2 == sscanf_s(input.c_str(), "%d / %d", &num, &den)) {
		return true;
	}
	return false;
}

int main(void) {
	const int SEP_LENGTH = 40;
	int num, den;
	int num2, den2;

	string input = "";
	cout << "Enter your fraction: ";
	getline(cin, input);

	// clear input for next fraction
	cin.ignore();

	string input2 = "";
	cout << "Enter your next fraction: ";
	getline(cin, input);

	// input validation
	if (isValid(input, num, den) && isValid(input2, num2, den2)) {
		cout << "Your initial fraction was: " << num << "/" << den << "..." << endl;
		Fraction fraction(num, den);
		Fraction fraction2(num2, den2);

		for (int i = 0; i < SEP_LENGTH; i++)
		{
			if (i == (SEP_LENGTH - 1)) {
				cout << endl;
			}
			cout << "-";
		}

		cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	}
	else {
		cout << "Unrecognized input format" << endl;
	}

	system("pause");
	return 0;
}