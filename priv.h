#pragma once
/*
    File: priv.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#include "gendepend.h"
#include "crypt.h"

class Priv {
private:
	// 0 == Read, 1 == Write, 2 == Admin
	int auth;
	Crypt crypt;
	std::string user;
	std::string password;

public:
	int getAuth();
	void login();
	void setKey();
	void setAdmin();
	void setCipher();
	void setAccess();
	void setNewUser();
	void setPassword();
	void setUserName();
};