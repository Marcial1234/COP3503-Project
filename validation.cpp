#pragma once
#include "validation.h"
#include "gendepend.h"

using namespace std;

// This file might give warnings. Not worrying about them for now.

// Possible list of enums to link back and forth to functions
// But most likely will be replaced by function pointers
// Array of max values of submenus somewhere

// "Globals"
enum MenuOptions
{
	Browse,
	Edit,
	Build,
	Settings
};

enum EditMenuOptions
{
	List,
	Move,
	AddFile, // Meh...
	AddEmployee,
	ViewEmployee,
	DeleteEmployee,
	AddFolder,
	EditFolder,
	DeleteFolder,
};

enum SettingsMenuOptions
{
	SetHash,
	SetCrypt,
	ChangePriv,
};

// End of "Globals".

using namespace std;

void SpitOutStupidity() {
	std::cout << "\nSorry, that was an invalid input, try again.\n" << std::endl;
	std::cin.clear();
	std::cin.ignore(1024, '\n');
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

string mainMenu[4] = { "Browse", "Edit", "Build", "Go to Settings" };
// Can have a lot of these for prompts.

enum Privs { Read, Write, Admin };

// Come up with ideas of why this should return the variable value.
void printGenericMenu(string placeHolder, vector<string> &v) {
	cout << placeHolder << endl;

	// Printing custom Menu based on vector parameters type
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << "\t" << i << ": " << v[i] << endl;
		
	// TBA: Actual implementation of this.
	// Menus with "No" on them don't really need this...
	// cout << "\t" << v.size() << ": To Go Back" << endl;
}

void printMainMenu() {
	int maxPrivValues[3] = { 1, 2, 4 };
	Privs auth = Admin;
	cout << "Please type one of the following:" << endl;

	// Printing custom Menu based on authorization type
	for (int i = 0; i < maxPrivValues[auth]; ++i)
		cout << "\t" << i << ": To " << mainMenu[i] << endl;
	cout << "\t" << maxPrivValues[auth] << ": To Exit" << endl;

	// Asking for user input. +1 so it exits on max +1
	int whatToDo = RecursivelyValitate(maxPrivValues[auth]+1);

	// Array of function pointers to the desired 'whatToDo' function
	// Go die arrays and ur const values.....
	// void (*functionPointerArr[whatToDo])();
}

void testMain() {
	// Need to actually get this from somewhere. Cannot hard set it
	printMainMenu();

	string instructions = "Do you want to change the cipher? (Y/N)\n";
	instructions += "(Warning: Changing the cipher might affect the success of encrypting and decrypting text.\n";
	vector<string> options = { "For Yes", "For No" };
	printGenericMenu(instructions, options);
	int response = RecursivelyValitate(options.size());

	if (response == 0) {
		options = { "Caesar Cipher", "Vigenere Cipher" };
		printGenericMenu("Cipher Options:\n", options);
		// cout << "\t" << "3. More options coming soon" << endl;
		
		int input = RecursivelyValitate(options.size());

		if (input == 0)
			cout << "Cipher successfully changed." << endl;
		else // if (input == "2"), again validation
			cout << "Cipher successfully changed." << endl;
	}
}

//void (*functptrMainMenu[])() = { Browse, Edit, Build, Settings };
//void (*functptrEdit[])() = { Rename, EditEmployee,  };
//void (*functptrSettings[])() = { Browse, Edit, Build, Settings };

// Shouldn't Build just be "Build Everything"?
//void (*functptrBuild[])() = { Browse, Edit, Build, Settings };
