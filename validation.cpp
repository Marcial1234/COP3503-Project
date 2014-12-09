#pragma once
#include "gendepend.h"
#include "validation.h"

using namespace std;

static void ClearCin()
{
	cin.clear();
	cin.ignore(1024, '\n');
}

static void SpitOutStupidity() {
	cout << "\nSorry, that was an invalid input, try again.\n" << endl;
	ClearCin();
}

// Numeric validation
static bool ValidateRange(long long int input, long long int  max) {
	// Use of Discrete right here
	return max > input && input >= 0;
}

static long long int RecursivelyValidate(long long int max) {
	long long int input = 0;

	if ((cin >> input) && ValidateRange(input, max))
		return input;
	else
	{
		SpitOutStupidity();
		return RecursivelyValidate(max);
	}
}

// String Validation
static string RecursivelyValidate() {
	string input = "";
	ClearCin();

	if (getline(cin, input))
		return input;
	else
	{
		SpitOutStupidity();
		return RecursivelyValidate();
	}
}

static void printGenericMenu(string placeHolder, vector<string> &v) {
	cout << placeHolder << endl;

	// Printing custom Menu based on vector parameters type
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "\t" << i << ": " << v[i] << endl;
}