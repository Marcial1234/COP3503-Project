#pragma once
/*
    File: priv.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#include "gendepend.h"

class Priv {
private:
	std::string user;
	std::string password;
	std::string auth;

public:
	std::string getAuth();
	void login();
	void setAdmin();
	void setAccess();
	void setNewUser();
	void setPassword();
	void setUserName();
};
