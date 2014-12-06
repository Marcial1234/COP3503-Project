/*
	File: Hash.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#include <string>

#ifndef hash_h
#define hash_h

class Hash {
private:
	int hash;
	string hashFunction;

public:
	Hash();
	int getHash(int value);
	int getHash(string value);
	int checkFunction(int);
	bool checkHash(int);
	void changeFunction();
};

#endif
