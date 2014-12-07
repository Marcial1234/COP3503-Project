#include "crypt.h"

using namespace std;

Crypt::Crypt() {
	// Ernie: I added a string variable called key. It seemed to be used later on (line 42) but was never declared.
	string key;
	string cipher = "Caesar";
	cout << "Please enter a key: " << endl;
	getline(cin, key);
}

string Crypt::encrypt() {
	// Validation needed here
	if (cipher == "Caesar")
		// Code goes here.
		;
	else if (cipher == "Vigenere")
		// Code goes here
		;
	else
		cout << "No cipher set, please rectify." << endl;
}

string Crypt::decrypt() {

	if (cipher == "Caesar")
        // Code goes here.
		return;
	else if (cipher == "Vigenere")
        // Code goes here.
		return;
	else
		cout << "No cipher set, please rectify." << endl;
}

string Crypt::getKey() {
	return key;
}

string Crypt::getCipher() {
	return cipher;
}

void Crypt::setKey() {

	cout << "Do you want to change the key? (Y/N): " << endl;
	// Marcial: will perform string validation later. Ignore the errors/case ambiguity for now.
	string response;
	getline(cin, response);

	// if (tolower(response) == 'n') {
	if (response == "y") {
		cout << "Enter the new key: " << endl;
		getline(cin, response);
		cout << "The key was successfully changed." << endl;
	} 
	// else if (tolower(response) == 'n') 
	else if (response == "n") 
		return;
	else 
		cout << "Error: Invalid input." << endl;
}

void Crypt::setCipher() {

	cout << "Do you want to change the cipher? (Y/N)" << endl;
	cout << "(Warning: Changing the cipher might affect the success of encrypting and decrypting text." << endl;
    // To make things explicit, I hope you guys don't mind if I rename them to cipher_response and key_response. 
	string response;
	getline(cin, response);

	if ( response == "y") {
		cout << "Cipher Options:" << endl;
		cout << "\t" << "1. Caesar Cipher" << endl;
		cout << "\t" << "2. Vigener Cipher" << endl;
		cout << "\t" << "3. More options coming soon" << endl;
		// Ernie: Once again, I have changed input to type string to play nice with getline().
		string input;
		getline(cin, input);

		// To be modified.
		if (input == "1") {
			if (cipher == "Caesar")
				cout << "The Caesar Cipher is already selected." << endl;
			else {
				cipher = "Caesar";
				cout << " The cipher was successfully changed." << endl;
			}
		}
		else if (input == "2") {
			if (cipher == "Vigenere")
				cout << "Vigenere Cipher already selected." << endl;
			else {
				cipher = "Vigenere";
				cout << "Cipher successfully changed." << endl;
			}
		}
		else 
			cout << "Error: Invalid input." << endl;
	}
}
