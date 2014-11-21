#include <string>
#include <iostream>

#ifndef CRYPT_H
#define CRYPT_H

class crypt{
private:
	string key;
	string cipher;

public:
	crypt();
	string encrypt();
	string decrypt();
	string getKey();
	string getCipher();
	void setKey();
	void setCipher();
};

#endif

