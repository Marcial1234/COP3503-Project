/*
	File: Hash.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts

	Submitted: December 5, 2014
*/

#include <string>

#ifndef Hash_h
#define Hash_h

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