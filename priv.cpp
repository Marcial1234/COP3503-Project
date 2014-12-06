#include "priv.h"

using namespace std;

void priv::pullUserRecords() {
	string username;
	string password;
	int authorization;
	
	while (!fileUsers.eof()) {
		// Reading order: [username] [password] [authorization]
		fileUsers >> username;
		filePasswords >> password;
		filePrivs >> authorization;
		cout << "PARSED: " << username << " " << password << " " << authorization << "\n";
		users[username] = password;
		privileges[username] = authorization;
	}
}

void priv::pushUserRecords() {
	// Iterate over maps, and output them to the file.
}

void priv::login() {

	pullUserRecords();

	if(users.empty()) {
        setAdmin();
	}

	// Repetition should start here.
	// Ernie: I changed cin to getline(). I hope that's OK.
	cout << "Please enter your username: " << endl;
	string user;
	getline(cin, user);
	cout << "Please enter your password: " << endl;
	string password;
	getline(cin, password);

	// Might add this to the class, as well as an iter for privileges.
	map<string, string>::iterator iter = users.find(user);

	if (iter == users.end() || iter->first != user || iter->second != password)
	{
		cout << "Incorrect username/password combination. Please enter correct information." << endl;
		cout << "Note: If you do not have a username and password, please contact your administrator for this system." << endl;
		
		login();
	}

	else
		auth = privileges[user];
}

void priv::setAdmin() {

	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();
	users[user] = password;
	privileges[user] = 3;
	// filePrivs << 3;
}

void priv::setNewUser() {

	cout << "Welcome to the Human Resources System (HRSys)!" << endl;
	cout << "To get started, you will first need to create a username and password." << endl;
	setUserName();
	setAccess();
	users[user] = password;
	privileges[user] = auth;
}

// Function for setting the user password.
void priv::setUserName() {

	cout << "Please enter your username: " << endl;
	string tempUsername;
	getline(cin, tempUsername);

	cout << "Please confirm your username: " << endl;
	string tempUsername2;
	getline(cin, tempUsername2);

	if(tempUsername == tempUsername2) {
		cout << "User name set." << endl;
		user = tempUsername;
		// fileUsers << tempUsername;
		setPassword();
	} 

	else {
		cout << "Error: Usernames do not match. Please retry." << endl;
		setUserName();
	}
}

// Function for setting the user password.
void priv::setPassword() {

	cout << "Please enter your password: " << endl;
	string tempPassword;
	getline(cin, tempPassword);

	cout << "Please confirm your password: " << endl;
	string tempPassword2;
	getline(cin, tempPassword2);

	if (tempPassword == tempPassword2) {
		cout << "Password set!" << endl;
		password = tempPassword;
		// filePasswords << tempPassword;
	} 

	else {
		cout << "Error: Passwords do not match. Please retry." << endl;
		setPassword();
	}
}

void priv::setAccess() {

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
		// filePrivs << 1;
		return;
	}

	if (privlevel == "2") {
		auth = 2;
		// filePrivs << 2;
		return;
	}

	if (privlevel == "3") {
		auth = 3;
		// filePrivs << 3;
		return;
	}

	cout << "Error: Invalid input. Please re-enter information." << endl;
	setAccess();
}

int priv::getAuth() {
	return auth;
}
