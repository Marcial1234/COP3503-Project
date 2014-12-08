#pragma once
#include "hash.h"
#include "validation.h"
#include "validation.cpp"

using namespace std;

Hash::Hash() {
	// Hash always defaults to standard hash function. 
	hashFunction = Standard;
}

// Marcial: No idea what's the point of this method still
int Hash::getHash(string value) {
	int num = checkFunction(1);
	int temphash = 0;

	if (num == 0)
		return 1;

	if (num == Standard) {
		for (int i = 0; i < value.length(); i++)
			temphash = (temphash << 4) + value.at(i);
	}
	if (num == Advanced) {
		for (int i = 0; i < value.length(); i++)
			temphash = (temphash << 4) + value.at(i);
	}

	// The simple hash function.
	if (num == Simple) {
		for (int i = 0; i < value.length(); i++)
			temphash = temphash + value.at(i);
	}

	return temphash;
}

bool Hash::checkHash(int checkVal) {
	return checkVal == hash;
}

int Hash::checkFunction(int check) {
	if (check == 1) {
		return hashFunction;
	}

	// cout << "Error: No valid hash function detected." << endl;
	string intructions = "Would you like to default to the standard hash function? (Y/N):\n";
	vector<string> options = { "No", "Yes" };
	printGenericMenu(intructions, options);
	RecursivelyValitate(options.size());
}

void Hash::changeFunction() {

	string intructions = "Your hash function options are as follows:\n";
	vector<string> options = { "Standard (standard hash, fast)", "Advanced (sophisticated hash, slowest)", "Simple (basic hash, fastest)" };
	printGenericMenu(intructions, options);
	hashFunction = (Hash::fx)RecursivelyValitate(options.size());
	cout << "Successfully changed Hash Function to" << options[hashFunction] << endl;

	// We can expand more options later if time permits.
	// cout << "Error: Please choose one of the listed options:" << endl;
	// changeFunction();
}

/*
int main()
{
	Hash pt = *(new Hash());

	return 0;
}
*/