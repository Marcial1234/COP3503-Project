#include <string>
#include <iostream>

using namespace std;

crypt() {
	cipher = "Caesar";
	cout << "please enter key" << endl;
	cin >> key;
}
string encrypt() {
	if(strcmp(cipher,"Caesar") == 0) {

		return;
	}
	if(strcmp(cipher,"Vigenere") == 0) {

		return;
	}
	cout << "no cipher set, please rectify" << endl;
}

string decrypt() {
	if(strcmp(cipher,"Caesar") == 0) {

		return;
	}
	if(strcmp(cipher,"Vigenere") == 0) {

		return;
	}
	cout << "no cipher set, please rectify" << endl;
}

string getKey() {
	return key;
}
string getCipher() {
	return cipher;
}

void setKey() {
	cout << "do you want to change the key? (Y/N)" << endl;
	char response;
	cin >> response;
	if(response == "Y" || response == "y") {
		cout << "enter new key" << endl;
		cin >> key;
		cout << "key successfully changed" << endl;
	} else if (response == "N" || response == "n") {
		return;
	} else {
		cout << "invalid input" << endl;
	}
}

void setCipher() {
	cout << "do you want to change the cipher? (Y/N)" << endl;
	cout << "(WARNING: changing cipher might effect the success of encrypting and decrypting text." << endl;
	char response;
	cin >> response;
	if(response == "Y" || response == "y") {
		cout << "Cipher options:" << endl;
		cout << "\t" << "1. Caesar Cipher" << endl;
		cout << "\t" << "2. Vigener Cipher" << endl;
		cout << "\t" << "3. more options coming soon" << endl;
		int input;
		cin >> input;
		if(input == 1) {
			if(strcmp(cipher,"Caesar") == 0) {
				cout << "Caesar Cipher already selected" << endl;
			} else {
				cipher = "Caesar";
				cout << "cipher successfully changed" << endl;
			}
		} else if(input == 2) {
			if(strcmp(cipher,"Vigenere") == 0) {
				cout << "Vigenere Cipher already selected" << endl;
			} else {
				cipher = "Vigenere";
				cout << "cipher successfully changed" << endl;
			}
		} else {
			cout << "invalid input" << endl;
		}
	}
}


