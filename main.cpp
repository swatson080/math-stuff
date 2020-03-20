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

int main() {

	// TODO:
	// break int down to vector representation backwards e.g. vector[0] represents the ones place
	// fast exponentiation, factorials, n choose k, etc.

		int x = getIntInput();

		std::cout << x << std::endl;

	return 0;
}

int getIntInput() {

	while(true) {
		// First get input as string
		std::string rawInput = "";
		rawInput = getStringInput("Enter an integer\n>");

		std::stringstream stream(rawInput);
		int value = -1;					// Using this to prevent behavior where entering an integer, spaces and then a character(s) would, on the next iteration, if the enter key was pressed, return the previously entered integer
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
	std::string rawInput;
	getline(std::cin,rawInput);
	return rawInput;

}
