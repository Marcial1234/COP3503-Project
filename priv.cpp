#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include "Priv_h"

using namespace std;

void pullUserRecords() {
	string tempstring;
	string tempstring2;
	int tempvalue;
	int counter = 0;
	while(!fileUsers.eof()) {
		fileUsers >> tempstring;
		filePasswords >> tempstring2;
		filePrivs >> tempvalue;
		cout << "PARSED: " << tempstring << " " << tempstring2 << " " << tempvalue << "\n";
		users.insert(make_pair(tempstring,tempstring2));
		privileges.insert(make_pair(tempstring,tempvalue));
		counter++;
	}
}

void pushUserRecords() {


}

void login() {
	pullUserRecords();
	if(users.Empty() == true) {
	    // Question: Are we assuming the first user to setup the system will be an admin?
        setAdmin();
	}
	cout << "Please enter your username: " << endl;
	cin >> user;
	cout << "Please enter your password: " << endl;
	cin >> password;
	checkPassword();
	for(int i = 0; i < 100; i++) {
		if(strcmp(user, &users[i][0]) == 0 && strcmp(password, &users[i][1]) == 0) {
			// Question: Why will priv be a two dimenstional array? 
			priv = users[i][2];
			return 1;
		}
	}
	cout << "Incorrect username/password combination. Please enter correct information." << endl;
	cout << "Note: If you do not have a username and password, please contact your administrator for this system." << endl;
	login();
}

void setAdmin() {
	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();
	users[user] = password;
	privileges[user] = 3;
	filePrivs << 3;
}

void setNewUser() {
	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();
	setAccess();
	users[user] = password;
	privileges[user] = auth;
}

void setUserName() {
	cout << "Please enter you username: " << endl;
	string tempUsername;
	cin >> tempUsername;
	cout << "Please confirm your username: " << endl;
	string tempUsername2;
	cin >> tempUsername2;
	if(strcmp (tempUsername, tempUsername2) == 0) {
		cout << "User name set." << endl;
		user = tempUsername;
		fileUsers << tempUsername;
		setPassword();
	} 
	else {
		cout << "Error: Usernames do not match. Please retry." << endl;
		setUserName();
	}
}

void setPassword() {
	cout << "Please enter your password: " << endl;
	string tempPassword;
	cin >> tempPassword;
	cout << "Please confirm your password: " << endl;
	string tempPassword2;
	cin >> tempPassword2;

	if (strcmp(tempPassword, tempPassword2) == 0) {
		cout << "Password set!" << endl;
		password = tempPassword;
		filePasswords << tempPassword;
	} 
	else {
		cout << "Error: Passwords do not match. Please retry." << endl;
		setPassword();
	}
}

void setAccess() {
	users[user] password;
	cout << "Set Privilege Level: " << endl;
	cout << "\t" << "1. Read-Only" << endl;
	cout << "\t" << "2. Read and Modify" << endl;
	cout << "\t" << "3. Full/Administrative Access" << endl;
	int privlevel;
	cin >> privlevel;
	if (privlevel == 1) {
		auth = 1;
		filePrivs << 1;
		return;
	}
	if (privlevel == 2) {
		auth = 2;
		filePrivs << 2;
		return;
	}
	if (privlevel == 3) {
		auth = 3;
		filePrivs << 3;
		return;
	}
	cout << "Error: Invalid input. Please re-enter information." << endl;
	setAccess();
}

int getAuth() {
	return auth;
}