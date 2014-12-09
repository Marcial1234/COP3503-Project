#pragma once
#include "crypt.h"
#include "validation.h"
#include "validation.cpp"
#include <stdio.h>

using namespace std;
//Constructor
Crypt::Crypt() {
	cipher = Caesar;
	key = "Jonathan Chien-Liang Liu";
}

//Method to encrypt a string of text into an unreadable form.
string Crypt::encrypt(string text) {

	int tempInt;
	char ch;
	string newstring;

	if (cipher == Caesar) {
		for (char& c : text) {
			tempInt = (int) c + (int) key[key.length()/2];
			ch = (char)tempInt;
			newstring += ch;
		}

		return newstring;
	}
	else {
		for (unsigned int i = 0; i < text.length(); ++i)
		{
			tempInt = (int) text[i] + (int) key[i];
			ch = (char)tempInt;
			newstring += ch;
		}

		return newstring;
	}
}

//Method to decrypt the previously encrypted text. 
string Crypt::decrypt(string text) {
	int tempInt;
	char ch;
	string newstring;

	if (cipher == Caesar) {
		for (char& c : text) {
			tempInt = (int) c - (int)key[key.length()/2];
			ch = tempInt;
			newstring += ch;
		}

		return newstring;
	}
	else
	{
		for (unsigned int i = 0; i < text.length(); ++i)
		{
			tempInt = (int)text[i] - (int)key[i];
			ch = (char)tempInt;
			newstring += ch;
		}
		return newstring;
	}
}

//Returns the cipher used to encrpyt/decrypt string text.
Crypt::CypherType Crypt::getCipher() {
	return cipher;
}

//Change the key used to encrypt/decrypt 
void Crypt::setKey() {
	vector<string> options = { "No", "Yes" };
	printGenericMenu("Do you want to change the key? (Y/N):\n", options);
	int response = RecursivelyValidate(options.size());

	if (response) {
		cout << "Enter the new key: " << endl;
		getline(cin, key);
		cout << "The key was successfully changed." << endl;
		// decrypt everything and then recrypt it
	}
}

//Set the Cipher
void Crypt::setCipher() {

	string instructions = "Do you want to change the cipher? (Y/N)\n";
	// Consider getting rid of this after the recryption works.
	instructions += "(Warning: Changing the cipher might affect the success of encrypting and decrypting text.\n";
	vector<string> options = { "No", "Yes" };
	printGenericMenu(instructions, options);
	int response = RecursivelyValidate(options.size());

	if (response) {
		options = { "Caesar Cipher", "Vigenere Cipher" };
		printGenericMenu("Cipher Options:", options);
		int input = RecursivelyValidate(options.size());

		cipher = (Crypt::CypherType)input;
		cout << "Cipher successfully changed." << endl;
	}
}
