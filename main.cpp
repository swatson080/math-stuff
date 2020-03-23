/*
 * main.cpp
 *
 *  Created on: Mar 19, 2020
 *      Author: stephen
 *
 *
 *
 */

#include <iostream>
#include <climits>
#include <sstream>
#include <vector>

int getIntInput();
std::string getStringInput(std::string message);
void initVector(int x, std::vector<int> &value);
void printVectorStandard(std::vector<int> &value);			// Prints the vector forwards
long long fastExp(int base, int exp);

int main() {

	// TODO:
	// fast exponentiation, factorials, n choose k, etc.
	// convert to base 2, base 16

		int userNumber1 = getIntInput();

		std::vector<int> value;

		initVector(userNumber1, value);
		printVectorStandard(value);

	return 0;
}

int getIntInput() {

	while(true) {
		// First get input as string
		std::string rawInput = "";
		rawInput = getStringInput("Enter an integer\n>");

		std::stringstream stream(rawInput);
		int value = -1;					// Using the assignment to -1 to prevent behavior where entering an integer, spaces and then a character(s) would, on the next iteration, if the enter key was pressed, return the previously entered integer
		char temp = '\0';				// You can use this to determine the first character of a bad input
		stream >> value;

		if(value && !(stream >> temp) && value >= 0 && value <= INT_MAX) {
			return value;
		}
		else {
			std::cout << "Bad input" << std::endl;
		}
	}
}

std::string getStringInput(std::string message) {

	std::cout << message;
	std::string rawInput = "";
	getline(std::cin,rawInput);
	return rawInput;

}

void initVector(int x, std::vector<int> &value) {

	int n;

	while(x > 0) {
		n = x % 10;
		value.push_back(n);
		x /= 10;
	}
}

void printVectorStandard(std::vector<int> &value) {

	int n = 0, p = 0, s= 0;

	for(std::vector<int>::iterator i = value.begin(); i != value.end(); ++i) {
		p = *i * fastExp(10,n);
		s += p;
		++n;
	}

	std::cout << s << std::endl;
}

long long fastExp(int base, int exp) {

	int p = 1;
	int s = base;
	int r = exp;

	while( r > 0) {
		if(r % 2 == 1) {
			p *= s;
		}
		s *= s;
		r /= 2;
	}

	return p;

}
