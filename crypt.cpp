#include "crypt.h"

using namespace std;

Crypt::Crypt() {
	string cipher = "Caesar";
	cout << "Please enter a key: " << endl;
	getline(cin, key);
}

string Crypt::encrypt(string text) {
	if (cipher == "Caesar") {
		int tempInt;
		char ch;
		string newstring;

		for(char& c : text) {
			tempInt = (int) c + (int) key[0];
			if(tempInt > 126)
				tempInt = (int) c - 126;

			ch = tempInt;
			newstring += ch;
		}

		return newstring;
	}
	else if (cipher == "Vigenere")
		// Code goes here
		return text;
}

string Crypt::decrypt(string text) {
	if (cipher == "Caesar") {
		int tempInt;
		char ch;
		string newstring;

		for(char& c : text) {
			// This does not nessesarily work all the time.
			tempInt = (int) c - (int) key[0];
			if(tempInt < 1)
				tempInt = (int) c + 126; 

			ch = tempInt;
			newstring += ch;
		}

		return newstring;
	} 
	else // if (cipher == "Vigenere")
        // Code goes here.
		return text;
}

string Crypt::getKey() {
	return key;
}

string Crypt::getCipher() {
	return cipher;
}

void Crypt::setKey() {
	// I doubt we should be even asking this types of questions.
	// No need for double verfication
	vector<string> options = { "For Yes", "For No" };
	printGenericMenu("Do you want to change the key? (Y/N):\n", options);
	int response = RecursivelyValitate(options.size());

	if (response == 0) {
		cout << "Enter the new key: " << endl;
		getline(cin, key); // No real validation needed here, since 'nothing' seems to break a string
		cout << "The key was successfully changed." << endl;
	}
	else //there will only be 2 values for response, thanks to validation 
		return;
}

void Crypt::setCipher() {
	// I doubt we should be even asking this types of questions.
	// No need for double verfication
	string instructions = "Do you want to change the cipher? (Y/N)\n";
	instructions += "(Warning: Changing the cipher might affect the success of encrypting and decrypting text.\n";
	vector<string> options = { "For Yes", "For No" };
	printGenericMenu(instructions, options);
	int response = RecursivelyValitate(options.size());

	if (response == 0) {
		options = { "Caesar Cipher", "Vigenere Cipher" };
		printGenericMenu("Cipher Options:", options);
		// cout << "\t" << "3. More options coming soon" << endl;
		
		int input = RecursivelyValitate(options.size());

		// 0 == false/Caesar, 1 == true/Vigenere. Go Back won't work
		if (input)
			cipher = "Vigenere";
		else
			cipher = "Caesar";
		cout << "Cipher successfully changed." << endl;
	}
}