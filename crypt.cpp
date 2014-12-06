#include "generic dependencies.h"
#include "crypt.h"

Crypt::Crypt() {
	cipher = "Caesar";
	cout << "Please enter key: " << endl;
	cin >> key;
}

string Crypt::encrypt() {
	if(cipher == "Caesar") {

		return;
	}
	if(cipher == "Vigenere") {

		return;
	}
	cout << "No cipher set, please rectify." << endl;
}

string Crypt::decrypt() {
	if(cipher == "Caesar") {

		return;
	}
	if(cipher == "Vigenere") {

		return;
	}
	cout << "No cipher set, please rectify." << endl;
}

string Crypt::getKey() {
	return key;
}

string Crypt::getCipher() {
	return cipher;
}

void Crypt::setKey() {
	cout << "Do you want to change the key? (Y/N)" << endl;
	char response;
	cin >> response;
	if(tolower(response) == 'y') {
		cout << "Enter new key: " << endl;
		cin >> key;
		cout << "Key was successfully changed." << endl;
	} else if (tolower(response) == 'n') {
		return;
	} else {
		cout << "Error: Invalid input." << endl;
	}
}

void Crypt::setCipher() {
	cout << "Do you want to change the cipher? (Y/N)" << endl;
	cout << "(Warning: Changing the cipher might affect the success of encrypting and decrypting text." << endl;
	char response;
	cin >> response;
	if(tolower(response) == 'y') {
		cout << "Cipher Options:" << endl;
		cout << "\t" << "1. Caesar Cipher" << endl;
		cout << "\t" << "2. Vigener Cipher" << endl;
		cout << "\t" << "3. More options coming soon" << endl;
		int input;
		cin >> input;

		// TBM
		if(input == 1) {
			if(cipher == "Caesar") {
				cout << "Caesar Cipher already selected." << endl;
			} else {
				cipher = "Caesar";
				cout << "Cipher was successfully changed." << endl;
			}
		} else if(input == 2) {
			if(cipher == "Vigenere") {
				cout << "Vigenere Cipher already selected." << endl;
			} else {
				cipher = "Vigenere";
				cout << "Cipher successfully changed." << endl;
			}
		} else {
			cout << "Error: Invalid input." << endl;
		}
	}
}
