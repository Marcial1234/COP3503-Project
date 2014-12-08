#pragma once
#include "gendepend.h"
#include "validation.h"

using namespace std;

// Marcial: Make these methods static later.

/*
	Documentation/How to Use:
		
		printMainMenu(){}:
		Prints the "Main Menu" based on a local definition of 'auth'

		printGenericMenu(string, vector<stirng>){}
		Menu generator. Generates the following:
		[action description/instructions]
			[i]: vector[i]
			...
		Example:
		printGenericMenu("Do you know your name?", { "No", "Yes" });
		Do you know your name?
			0. No
			1. Yes

		RecursivelyValitate(maxNumber){}
		Returns the input of a number ONLY LOWER than the passed max/upper limit.

		Did not combine them (as in Recur.Val. inside Gener.Menu). MIGHT do so later.
		Wanted flexibility.
 */


// This file might give warnings/type converstion errors. Not worrying about them for now.

void SpitOutStupidity() {
	cout << "\nSorry, that was an invalid input, try again.\n" << endl;
	cin.clear();
	cin.ignore(1024, '\n');
}

// Numeric validation
bool ValidateRange(long long int input, long long int  max) {
	// Use of Discrete right here
	return max > input && input >= 0;
}

long long int RecursivelyValitate(long long int max) {
	long long int input = 0;

	if ((cin >> input) && ValidateRange(input, max))
		return input;
	else
	{
		SpitOutStupidity();
		return RecursivelyValitate(max);
	}
}

// String Validation
bool ValidateRange(string input, vector<string> &options) {
	// Find if the input is in the map/vector
	for (unsigned int i = 0; i < options.size(); ++i)
	{
		if (options[i] == input)
			return true;
	}
	return false;
}

string RecursivelyValitate(vector<string> &options) {
	string input = "";

	if ((cin >> input) && ValidateRange(input, options))
		return input;
	else
	{
		SpitOutStupidity();
		return RecursivelyValitate(options);
	}
}

void printGenericMenu(string placeHolder, vector<string> &v) {
	cout << placeHolder << endl;

	// Printing custom Menu based on vector parameters type
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "\t" << i << ": " << v[i] << endl;
}

void printMainMenu(int auth) {
	int maxPrivValues[3] = { 1, 2, 4 };
	string mainMenu[4] = { "Browse", "Edit", "Build", "Settings" };
	cout << "Please type one of the following:" << endl;

	// Printing custom Menu based on authorization type
	for (int i = 0; i < maxPrivValues[auth]; ++i)
		cout << "\t" << i << ": To " << mainMenu[i] << endl;
	cout << "\t" << maxPrivValues[auth] << ": To Exit" << endl;
}