#include <string>
#include <iostream>

#ifndef crypt_h
#define crypt_h

class crypt {
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

