#include "crypt.h"

Crypt::Crypt() {
	// Ernie: I added a string variable called key. It seemed to be used later on (line 42) but was never declared.
	string cipher = "Caesar";
	string key;
	cout << "Please enter a key: " << endl;
	getline(cin, key);
}

string Crypt::encrypt() {

	if(cipher == "Caesar") {
        // Code goes here.
		return;
	}

	if(cipher == "Vigenere") {
        // Code goes here.
		return;
	}

	cout << "No cipher set, please rectify." << endl;
}

string Crypt::decrypt() {

	if(cipher == "Caesar") {
        // Code goes here.
		return;
	}

	if(cipher == "Vigenere") {
        // Code goes here.
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

	cout << "Do you want to change the key? (Y/N): " << endl;
	// Ernie: I changed response to type string to play nice with getline().
	//        I also renamed "response" to "key_response" to better differentiate between "cipher_response".
	//        It probably won't matter for the end-user, but I'd want to prevent any confusion in our team.
	string key_response;
	getline(cin, response);

	if (tolower(response) == "y") {
		cout << "Enter the new key: " << endl;
		getline(cin, key_response);
		cout << "The key was successfully changed." << endl;
	} 

	else if (tolower(response) == 'n') 
		return;

	else 
		cout << "Error: Invalid input." << endl;
}

void Crypt::setCipher() {

	cout << "Do you want to change the cipher? (Y/N)" << endl;
	cout << "(Warning: Changing the cipher might affect the success of encrypting and decrypting text." << endl;
	// Ernie: Just a warning, but response is already defined in setKey (see above). 
    // To make things explicit, I hope you guys don't mind if I rename them to cipher_response and key_response. 
	string cipher_response;
	getline(cin, cipher_response);

	if(tolower(response) == 'y') {
		cout << "Cipher Options:" << endl;
		cout << "\t" << "1. Caesar Cipher" << endl;
		cout << "\t" << "2. Vigener Cipher" << endl;
		cout << "\t" << "3. More options coming soon" << endl;
		// Ernie: Once again, I have changed input to type string to play nice with getline().
		string input;
		getline(cin, input);

		// To be modified.
		if(input == "1") {
			if (cipher == "Caesar") {
				cout << "The Caesar Cipher is already selected." << endl;
			} else {
				cipher = "Caesar";
				cout << " The cipher was successfully changed." << endl;
			}
		}

		else if(input == "2") {
			if(cipher == "Vigenere") {
				cout << "Vigenere Cipher already selected." << endl;
			}
			else {
				cipher = "Vigenere";
				cout << "Cipher successfully changed." << endl;
			}
		}

		else 
			cout << "Error: Invalid input." << endl;
	}
}
