#pragma once
#include "crypt.h"
#include "validation.h"
#include "validation.cpp"
#include <stdio.h>

using namespace std;

Crypt::Crypt() {
	cipher = Caesar;
	key = "Jonathan Chien-Liang Liu";
	// Marcial: Maybe only show this when they want to change it?
	// cout << "Please enter a key: " << endl;
	// getline(cin, key);
}

string Crypt::encrypt(string text) {

	int tempInt;
	char ch;
	string newstring;

	// Not nessarily works as wanted on file. Need to verify
	if (cipher == Caesar) {
		for (char& c : text) {
			tempInt = (int) c + (int) key[key.length()/2];
			ch = (char)tempInt;
			newstring += ch;
		}

		return newstring;
	}
	else {//if (cipher == Vigenere) {
		for (unsigned int i = 0; i < text.length(); ++i)
		{
			tempInt = (int) text[i] + (int) key[i];
			ch = (char)tempInt;
			newstring += ch;
		}

		return newstring;
	}
}

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
	else //if (cipher == Vigenere)
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

/* 
string Crypt::XOREncryption(string input)
{
	string output = input;

	for (int i = 0; i < input.size(); i++)
		output[i] = char(input[i] & key[i % (sizeof(key))]);

	return output;
}
*/

string Crypt::getKey() {
	return key;
}

Crypt::CypherType Crypt::getCipher() {
	return cipher;
}

void Crypt::setKey() {

	// I doubt we should be even asking these type of questions.
	// No need for double verfication.
	vector<string> options = { "No", "Yes" };
	printGenericMenu("Do you want to change the key? (Y/N):\n", options);
	int response = RecursivelyValitate(options.size());

	if (response) {
		cout << "Enter the new key: " << endl;
		getline(cin, key); // No real validation needed here, since 'nothing' seems to break a string
		cout << "The key was successfully changed." << endl;
		// decrypt everything and then recrypt it
	}
}

void Crypt::setCipher() {

	// I doubt we should be even asking these type of questions.
	// No need for double verfication.
	string instructions = "Do you want to change the cipher? (Y/N)\n";
	// Consider getting rid of this after the recryption works.
	instructions += "(Warning: Changing the cipher might affect the success of encrypting and decrypting text.\n";
	vector<string> options = { "No", "Yes" };
	printGenericMenu(instructions, options);
	int response = RecursivelyValitate(options.size());

	if (response) {
		options = { "Caesar Cipher", "Vigenere Cipher" }; //, "XOR Encryption"
		printGenericMenu("Cipher Options:", options);
		// cout << "\t" << "3. More options coming soon" << endl;
		
		int input = RecursivelyValitate(options.size());

		cipher = (Crypt::CypherType)input;
		cout << "Cipher successfully changed." << endl;
	}
}

// Testing
/*
int main()
{
	Crypt test = *(new Crypt);
	cout << "Tell me something i don't know\n";
	cout << (char)-20 << endl;
	string input = "";
	getline(cin, input);
	cout << test.encrypt(input) << endl;
	cout << test.decrypt(input) << endl;
	
	cout << test.decrypt(test.encrypt(input)) << endl;

	system("Pause");

	return 0;
}
*/