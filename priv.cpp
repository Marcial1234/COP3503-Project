#include "priv.h"
#include "crypt.h"

using namespace std;

void Priv::login() {

	ifstream usersFile ("users.txt");
	ifstream passFile ("pass.txt");
	ifstream privsFile ("privs.txt");
	//ifstream settingsFile ("set.txt");

	Crypt crypt = *(new Crypt());

	if(usersFile.is_open() == false) {
		setAdmin();
	}
	cout << "Login page:" << "\n" << endl;
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
			line1 = crypt.decrypt(line1);
			line2 = crypt.decrypt(line2);
			if(line1 == user && line2 == password) {
				auth = line3;
				success = true;
				cout << "login successful" << "\n" << endl;
			}
		}
		if(success == false) {
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
	privsFile << "\n" << 3;
	
}

void Priv::setNewUser() {

	//cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	//cout << "To get started, you will first need to create a username and password." << endl;
	
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
		usersFile << "\n" << user;
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
		passFile << "\n" << password;

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
		
		ofstream privsFile ("privs.txt",ios_base::app);
		privsFile << "\n" << 1;

		return;
	}

	if (privlevel == "2") {
		auth = 2;
		
		ofstream privsFile ("privs.txt",ios_base::app);
		privsFile << "\n" << 2;

		return;
	}

	if (privlevel == "3") {
		auth = 3;
		
		ofstream privsFile ("privs.txt",ios_base::app);
		privsFile << "\n" << 3;

		return;
	}

	cout << "Error: Invalid input. Please re-enter information." << endl;
	setAccess();
}

string Priv::getAuth() {
	return auth;
}



int tempAuth;


int main() {
	Priv priv = *(new Priv());
	priv.login();
	
	tempAuth = 1;

	priv.setNewUser();

	return 0;
}
