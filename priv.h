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
	// Objects that handles encryption
	Crypt crypt;
	// Temporary username
	std::string user;
	// Temporary password
	std::string password;

public:
	// Get's the current user's authorization
	int getAuth();
	// Starts the Login process
	void login();
	// Prompts the user to the encryption key
	void setKey();
	// Gives the current user Admin priviledges
	void setAdmin();
	// Prompts the user to which encryption mechanism to use
	void setCipher();
	// Sets the access of a specific 
	void setAccess();
	// Creates a new user
	void setNewUser();
	// Function for setting the user password.
	void setPassword();
	// Function for setting the user username.
	void setUserName();
};