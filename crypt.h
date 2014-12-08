#pragma once
/*
    File: crypt.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#include "gendepend.h"

class Crypt {
	
private:
	std::string key;
	std::string cipher;
	std::string getKey();
	std::string getCipher();

public:
	Crypt();
	void setKey();
	void setCipher();
	std::string encrypt(std::string text);
	std::string decrypt(std::string text);
};
