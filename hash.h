/*
	File: Hash.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts

	Submitted: December 5, 2014
*/

#include <string>

#ifndef hash_h
#define hash_h

class hash {
private:
	int hash;
	string hashFunction;

public:
	Hash();
	int getHash(int value);
	int getHash(string value);
	bool checkHash();
	void checkFunction();
	void changeFunction();
};

#endif
