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
	std::string key;
	std::string cipher;

public:
	Crypt();
	void setKey();
	void setCipher();
	std::string getKey();
	std::string encrypt();
	std::string decrypt();
	std::string getCipher();
};

#endif
