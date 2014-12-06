/*
    File: crypt.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#ifndef crypt_h
#define crypt_h

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