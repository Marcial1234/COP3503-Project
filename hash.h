#pragma once
/*
	File: Hash.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#include "gendepend.h"

class Hash {

private:
	long long int hash;
	enum fx { Standard, Advanced, Simple };
	fx hashFunction;

public:
	Hash();
	long long int getHash(long long int value);
	bool checkHash(int);
	void changeFunction();
};
