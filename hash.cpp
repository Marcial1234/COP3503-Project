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
long long int Hash::getHash(long long int value) {
	long long int temphash = 0;

	if (hashFunction == Standard) {
		temphash = (temphash << 4) + value % 1111;	
	}
	if (hashFunction == Advanced) {
		temphash = (temphash << 4) + value % 1111;
	}
	// The simple hash function.
	if (hashFunction == Simple) {
			temphash = temphash + value % 1111;
	}

	return temphash;
}

bool Hash::checkHash(int checkVal) {
	return checkVal == hash;
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
