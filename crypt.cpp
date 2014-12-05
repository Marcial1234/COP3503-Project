#include <string>
#include <iostream>

#include "crypt.h"

using namespace std;

crypt() {
	cipher = "Caesar";
	cout << "Please enter key: " << endl;
	cin >> key;
}

string encrypt() {
	if(strcmp(cipher,"Caesar") == 0) {

		return;
	}
	if(strcmp(cipher,"Vigenere") == 0) {

		return;
	}
	cout << "No cipher set, please rectify." << endl;
}

string decrypt() {
	if(strcmp(cipher,"Caesar") == 0) {

		return;
	}
	if(strcmp(cipher,"Vigenere") == 0) {

		return;
	}
	cout << "No cipher set, please rectify." << endl;
}

string getKey() {
	return key;
}

string getCipher() {
	return cipher;
}

void setKey() {
	cout << "Do you want to change the key? (Y/N)" << endl;
	char response;
	cin >> response;
	if(response == "Y" || response == "y") {
		cout << "Enter new key: " << endl;
		cin >> key;
		cout << "Key was successfully changed." << endl;
	} else if (response == "N" || response == "n") {
		return;
	} else {
		cout << "Error: Invalid input." << endl;
	}
}

void setCipher() {
	cout << "Do you want to change the cipher? (Y/N)" << endl;
	cout << "(Warning: Changing the cipher might affect the success of encrypting and decrypting text." << endl;
	char response;
	cin >> response;
	if(response == "Y" || response == "y") {
		cout << "Cipher Options:" << endl;
		cout << "\t" << "1. Caesar Cipher" << endl;
		cout << "\t" << "2. Vigener Cipher" << endl;
		cout << "\t" << "3. More options coming soon" << endl;
		int input;
		cin >> input;
		if(input == 1) {
			if(strcmp(cipher,"Caesar") == 0) {
				cout << "Caesar Cipher already selected." << endl;
			} else {
				cipher = "Caesar";
				cout << "Cipher was successfully changed." << endl;
			}
		} else if(input == 2) {
			if(strcmp(cipher,"Vigenere") == 0) {
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
