#include "hash.h"

Hash::Hash() {
	// Hash always defaults to standard hash function. 
	hashFunction = "Standard";
}

// No clue but what is meant by "value.length", are you sure it should be an int or a string?
int Hash::getHash(int value) {

	int num = checkFunction(1);
	int temphash = 0;

	if (num == 0) {
		return 1;
	}

	// The standard hash function.
	if (num == 1) {
		for (int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
		}
	}

	// The advanced hash function.
	if (num == 2) {
		for (int i = 0; i < value.length(); i++) {
			temphash = (temphash << 4) + value.charAt(i);
		}
	}

	// The simple hash function.
	if (num == 3) {
		for (int i = 0; i < value.length(); i++) {
			temphash = temphash + value.charAt(i);
		}
	}

	return temphash;
}

string Hash::getHash(string value) {

	int num = checkFunction(2);
	int temphash = 0;

	if (num == 0) {
		cout << "Error: Invalid hash function, please change." << endl;
		return 1;
	}

	// The standard hash function.
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

	// The advanced hash funciton.
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

	// The simple hash function.
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

bool Hash::checkHash(int checkVal) {
	if(checkVal == hash) {
		return true;
	} else {
		return false;
	}
}

int Hash::checkFunction(int check) {

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
	// Changed char to string to play nice with getline().
	string input;
    getline(cin, input);

	if(tolower(input) == 'y') {
		return 1;
	} 

	else {
		cout << "Warning: Hash value not calculated." << endl;
	}

	return 0;
}

void Hash::changeFunction() {

	cout << "Your hash function options are as follows." << endl;
	cout << "\t" << "1. Standard (standard hash, fast)" << endl;
	cout << "\t" << "2. Advanced (sophisticated hash, slowest)" << endl;
	cout << "\t" << "3. Simple (basic hash, fastest)" << endl;
    
    // Ernie: Changed choice to string to play nice with getline().
	string choice;
	getline(cin, choice);

	if (choice == 1) {
		hashFunction = "Standard";
		return;
	}

	if (choice == 2) {
		hashFunction = "Advanced";
		return;
	}

	if (choice == 3) {
		hashFunction = "Simple";
		return;
	}

	else {
		cout << "Invalid input was detected. Please try again." << endl;
		changeFunction();
	}

	// We can expand more options later if time permits.
	cout << "Error: Please choose one of the listed options:" << endl;
	changeFunction();
}