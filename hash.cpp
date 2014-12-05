#include <string>
#include <cstring>
#include <iostream>

#include "hash.h"

using namespace std;

Hash() {
	//Hash always defaults to standard hash function. 
	// Ernie: I corrected "standard" to "Standard", as it is referenced in CheckFunction().
	hashFunction = "Standard";
}

int getHash(int value) {
	int num = checkFunction(1);
	int temphash = 0;
	if (num == 0) {
		return 1;
	}
	//Standard hash function
	if (num == 1) {
		for (int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
		}
	}
	//Advanced hash function
	if (num == 2) {
		for (int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
		}
	}
	//Simple hash function
	if (num == 3) {
		for (int i = 0; i < value.length(); i++) {
			temphash = temphash + value.charAt(i);
		}
	}
	return temphash;
}

int getHash(string value) {
	int num = checkFunction(2);
	int temphash = 0;
	if (num == 0) {
		cout << "Error: Invalid hash function, please change." << endl;
		return 1;
	}
	//Standard hash function
	if (num == 1) {
		for(int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
			int bits = temphash & OxF0000000;
			if(bits != 0) {
				temphash ^= bits >> 24;
			}
		temphash &= ~bits;
		}
		return temphash;
	}
	//Advanced hash funciton
	if (num == 2) {
		for(int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
			int bits = temphash & OxF0000000;
			if(bits != 0) {
				temphash ^= bits >> 24;
			}
		temphash &= ~bits;
		}
		return temphash;
	}
	//Simple hash function
	if (num == 3) {
		for(int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
			int bits = temphash & OxF0000000;
			if(bits != 0) {
				temphash ^= bits >> 24;
			}
		temphash &= ~bits;
		}
		return temphash;
	}
}

bool checkHash(int checkVal) {
	if(checkVal == hash) {
		return true;
	} else {
		return false;
	}
}

int checkFunction(int check) {
	// If the input is a integer.
	if(check == 1) {
		// Confirms a standard hash function.
		if (strcmp(hashFunction,"Standard") == 0) {
			return 1;
		}
		if (strcmp(hashFunction,"Advanced") == 0) {
			return 2;
		}
		if (strcmp(hashFunction,"Simple") == 0) {
			return 3;
		}
	}
	// If the input is a string.
	if(check == 2) {
		// Confirms a standard hash function.
		if (strcmp(hashFunction,"Standard") == 0) {
			return 1;
		}
		if (strcmp(hashFunction,"Advanced") == 0) {
			return 2;
		}
		if (strcmp(hashFunction,"Simple") == 0) {
			return 3;
		}
	}
	cout << "Error: No valid hash function detected." << endl;
	cout << "Would you like to default to the standard hash function? (Y/N): " << endl;
	char input;
	cin >> input;
	// Ernie: A minor comment - I'm pretty sure there's an ignore case method for <string> somewhere.
	if(input == 'Y' || input == 'y') {
		return 1;
	} 
	else {
		cout << "Warning: Hash value not calculated." << endl;
	}
	return 0;
}

void changeFunction() {
	cout << "Your hash function options are: " << endl;
	cout << "\t" << "1. Standard (standard hash function, moderate speed)" << endl;
	cout << "\t" << "2. Advanced (more sophisticated hash function, slower)" << endl;
	cout << "\t" << "3. Simple (least sophisticed, fastest speed)" << endl;
	int choice;
	cin >> choice;
	if(choice == 1) {
		hashFunction = "Standard";
		return;
	}
	if(choice == 2) {
		hashFunction = "Advanced";
		return;
	}
	if(choice == 3) {
		// Ernie: Added missing semicolon to line 120.
		hashFunction = "Simple";
		return;
	}
	// Expand more options later.
	cout << "Error: Please choose one of the listed options:" << endl;
	changeFunction();
}
