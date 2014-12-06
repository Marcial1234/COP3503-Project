/*
    File: crypt.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#ifndef CRYPT_H
#define CRYPT_H

#include "gendepend.h"

class Crypt {
private:
	string key;
	string cipher;

public:
	Crypt();
	void setKey();
	void setCipher();
	string getKey();
	string encrypt();
	string decrypt();
	string getCipher();
};

#endif
