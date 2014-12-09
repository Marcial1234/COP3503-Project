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
	user = RecursivelyValidate();
	cout << "Please enter your password: " << endl;
	password = RecursivelyValidate();

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
	if(setUserName() == false) {
		return;
	}
	setAccess();
}

// Function for setting the user password.
bool Priv::setUserName() {
	cout << "Setting new user: " << "\n" << endl;
	cout << "Please enter your username: " << endl;
	string tempUsername = RecursivelyValidate();

	cout << "Please confirm your username: " << endl;
	string tempUsername2 = RecursivelyValidate();

	ifstream readFile ("users.txt");
	string newline;
	while(getline(readFile,newline)) {
			if(newline == tempUsername) {
				cout << "Error: " << newline << " already exists." << endl;
				return false;
			}
	}

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
	return true;
}

// Function for setting the user password.
void Priv::setPassword() {

	cout << "Please enter your password: " << endl;
	string tempPassword = RecursivelyValidate();

	cout << "Please confirm your password: " << endl;
	string tempPassword2 = RecursivelyValidate();

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
