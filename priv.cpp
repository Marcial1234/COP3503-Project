#pragma once
#include "priv.h"
#include "crypt.h"
#include "crypt.cpp"
#include "validation.h"
#include "validation.cpp"

using namespace std;

void Priv::login() {

	ifstream usersFile ("users.txt");
	ifstream passFile ("pass.txt");
	ifstream privsFile ("privs.txt");
	//ifstream settingsFile ("set.txt");

	crypt = *(new Crypt());

	/*
		Test this:
			When file Doesn't have an admin by default.
			When it does have one.
	*/ 

	if (usersFile.is_open() == false)
		setAdmin();

	cout << "Login page:" << "\n" << endl;
	cout << "Please enter your username: " << endl;
	getline(cin, user);
	cout << "Please enter your password: " << endl;
	getline(cin, password);

	string line1;
	string line2;
	string line3;

	if (usersFile.is_open() && passFile.is_open() && privsFile.is_open()) {
		bool success = false;

		while(getline(usersFile,line1) && getline(passFile,line2) && getline(privsFile,line3)) {
			line1 = crypt.decrypt(line1);
			line2 = crypt.decrypt(line2);
			if (line1 == user && line2 == password) {
				auth = stoi(line3);
				success = true;
				cout << "login successful" << "\n" << endl;
			}
		}

		if (!success) {
			cout << "Username and/or password incorrect\n";
			cout << "Note: If you do not have an account please contact an administrator\n" << endl;

			login();
		}	
	}
} 

void Priv::setAdmin() {
	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();

	ofstream privsFile ("privs.txt",ios_base::app);
	privsFile << 2 << endl;
}

void Priv::setNewUser() {
	setUserName();
	setAccess();
}

// Function for setting the user password.
void Priv::setUserName() {
	cout << "Setting new user: " << "\n" << endl;
	cout << "Please enter your username: " << endl;
	string tempUsername;
	getline(cin, tempUsername);

	cout << "Please confirm your username: " << endl;
	string tempUsername2;
	getline(cin, tempUsername2);

	if (tempUsername == tempUsername2) {
		cout << "User name set." << endl;
		user = tempUsername;

		ofstream usersFile ("users.txt",ios_base::app);
		Crypt crypt = *(new Crypt());
		user = crypt.encrypt(user);
		usersFile << user << endl;;
		setPassword();
	}
	else {
		cout << "Error: Usernames do not match. Please retry." << endl;
		setUserName();
	}
}

// Function for setting the user password.
void Priv::setPassword() {

	cout << "Please enter your password: " << endl;
	string tempPassword;
	getline(cin, tempPassword);

	cout << "Please confirm your password: " << endl;
	string tempPassword2;
	getline(cin, tempPassword2);

	if (tempPassword == tempPassword2) {
		cout << "Password set!" << endl;
		password = tempPassword;
		
		ofstream passFile ("pass.txt",ios_base::app);
		Crypt crypt = *(new Crypt());
		password = crypt.encrypt(password);
		passFile << password << endl;
	}
	else {
		cout << "Error: Passwords do not match. Please retry." << endl;
		setPassword();
	}
}

void Priv::setAccess() {
	// users[user] password;
	vector<string> options = { "Read-Only", "Read and Modify", "Full/Administrative Access" };
	printGenericMenu("Set Privilege Level:", options);
	int input = RecursivelyValidate(options.size());

	ofstream privsFile ("privs.txt",ios_base::app);
	auth = input;
	privsFile << input << endl;
}

int Priv::getAuth() {
	return auth;
}

void Priv::setCipher() {
	crypt.setCipher();
}

void Priv::setKey() {
	crypt.setKey();
}
