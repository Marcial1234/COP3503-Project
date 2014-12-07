/*
	File: Hash.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#ifndef HASH_H
#define HASH_H

#include "gendepend.h"

class Hash {
private:
	int hash;
	std::string hashFunction;

public:
	Hash();
	int getHash(int value);
	int getHash(std::string value);
	int checkFunction(int);
	bool checkHash(int);
	void changeFunction();
};

#endif
