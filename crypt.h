#pragma once
/*
    File: crypt.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#include "gendepend.h"

class Crypt {
	
private:
	// Encryption key
	std::string key;
	// Returns a the encryption key
	std::string getKey();
	// Enumerator for the chipher type
	enum CypherType { Caesar, Vigenere};
	// Cipher being used
	CypherType cipher;
	// Gets the current cypher being used
	CypherType getCipher();

public:
	// Constructor
	Crypt();
	// Sets a new encryption key
	void setKey();
	// Changes the current cipher being used
	void setCipher();
	// Enrypts a string
	std::string encrypt(std::string text);
	// Decrypts a string
	std::string decrypt(std::string text);
};
