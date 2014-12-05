/*
	File: Priv.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#include <string>
#include <map>
#include <ifstream>

#ifndef priv_h
#define priv_h

class priv {
private:
	std::ifstream fileUsers("userRecordsUsers.txt");
	std::ifstream filePasswords("userRecordsPasswords.txt");
	std::ifstream filePrivs("userRecords3Privs.text");
	std::map<string,string> users;
	std::map<string,int> privileges;
	string user;
	string password;
	//auth levels are 1) read 2) read and write 3) read, write, and execute
	//some information will only be accessible at level 3, the admin level
	int auth;

public:
	void pullUserRecords();
	void pushUserRecords();
	void login();
	void setAdmin();
	void setNewUser();
	void setUserName();
	void setPassword();
	void setAccess();
	int getAuth();
};

#endif
