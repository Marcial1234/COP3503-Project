#include "priv.h"

using namespace std;

void Priv::login() {

	fstream usersFile ("users.txt");
	fstream passFile ("pass.txt");
	fstream privsFile ("privs.txt");

	if(usersFile.is_open() == false) {
		setAdmin();
	}

	cout << "Please enter your username: " << endl;
	string user;
	getline(cin, user);
	cout << "Please enter your password: " << endl;
	string password;
	getline(cin, password);

	string line1;
	string line2;
	string line3;
	if(usersFile.is_open() && passFile.is_open() && privsFile.is_open()) {
		bool success = false;
		while(getline(usersFile,line1) && getline(passFile,line2) && getline(privsFile,line3)) {
			if(line1 == user && line2 == password) {
				auth = line3;
				success = true;
			}
		}
		if(success == false) {
			cout << "Username and/or password incorrect\n";
			cout << "Note: If you do not have an account please contact an administrator\n";

			login();
		}
		
	}
	usersFile.close();
	passFile.close();
	privsFile.close();
} 

void Priv::setAdmin() {

	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();

	fstream privsFile ("privs.txt");
	privsFile << 3;
	privsFile.close();
}

void Priv::setNewUser() {

	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();
	setAccess();
}

// Function for setting the user password.
void Priv::setUserName() {

	cout << "Please enter your username: " << endl;
	string tempUsername;
	getline(cin, tempUsername);

	cout << "Please confirm your username: " << endl;
	string tempUsername2;
	getline(cin, tempUsername2);

	if (tempUsername == tempUsername2) {
		cout << "User name set." << endl;
		user = tempUsername;
		
		fstream usersFile ("users.txt");
		usersFile << user;
		usersFile.close();

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
		
		fstream passFile ("pass.txt");
		cout << password;
		passFile.close();

	}
	else {
		cout << "Error: Passwords do not match. Please retry." << endl;
		setPassword();
	}
}

void Priv::setAccess() {

	// users[user] password;
	// Ernie: I changed privlevel to a string so getline() would play nice.
	cout << "Set Privilege Level: " << endl;
	cout << "\t" << "1. Read-Only" << endl;
	cout << "\t" << "2. Read and Modify" << endl;
	cout << "\t" << "3. Full/Administrative Access" << endl;
	string privlevel;
	getline(cin, privlevel);

	// Validation
	if (privlevel == "1") {
		auth = 1;
		
		fstream privsFile ("privs.txt");
		privsFile << 1;
		privsFile.close();

		return;
	}

	if (privlevel == "2") {
		auth = 2;
		
		fstream privsFile ("privs.txt");
		privsFile << 2;
		privsFile.close();

		return;
	}

	if (privlevel == "3") {
		auth = 3;
		
		fstream privsFile ("privs.txt");
		privsFile << 3;
		privsFile.close();

		return;
	}

	cout << "Error: Invalid input. Please re-enter information." << endl;
	setAccess();
}

string Priv::getAuth() {
	return auth;
}

/*

int tempAuth;


int main() {
	
	Priv priv = *(new Priv());
	priv.login();
	
	tempAuth = 1;

	return 0;
}

*/