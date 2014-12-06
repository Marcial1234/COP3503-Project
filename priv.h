/*
    File: priv.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/
#ifndef PRIV_H
#define PRIV_H

#include "gendepend.h"

class Priv {
private:
	// these are ONLY input streams (they only read).
	// Need output streams, and the file they're looking at needs to be declared later on 
	std::ifstream fileUsers;
	std::ifstream filePasswords;
	std::ifstream filePrivs;
	// sample output stream
	std::ostream usersWritter;


	std::ifstream fileReader;
	std::ostream fileWriter;

	std::map<std::string, std::string> users;
	std::map<std::string, int> privileges;
	std::string user;
	std::string password;
	//auth levels are 1) read 2) read and write 3) read, write, and execute
	//some information will only be accessible at level 3, the admin level
	int auth;

public:
	int getAuth();
	void login();
	void setAdmin();
	void setAccess();
	void setNewUser();
	void setPassword();
	void setUserName();
	void pullUserRecords();
	void pushUserRecords();
};

#endif
