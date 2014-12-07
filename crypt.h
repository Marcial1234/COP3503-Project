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
	// Marcial: The user shouldn't have acces to the following 
	std::string getKey();
	std::string getCipher();

public:
	Crypt();
	void setKey();
	void setCipher();
	std::string encrypt();
	std::string decrypt();
};

#endif
