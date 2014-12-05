#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class priv {
private:
	// these are ONLY input streams (they only read).
	// Need output streams, and the file they're looking at needs to be declared later on 
	ifstream fileUsers;
	ifstream filePasswords;
	ifstream filePrivs;
	// sample output stream
	ostream usersWritter;

	map<string, string> users;
	map<string, int> privileges;
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

void priv::pullUserRecords() {
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

void priv::pushUserRecords() {


}

void priv::login() {
	pullUserRecords();

	if(users.empty()) {
	    // Question: Are we assuming the first user to setup the system will be an admin?
        setAdmin();
	}
	cout << "Please enter your username: " << endl;
	cin >> user;
	cout << "Please enter your password: " << endl;
	cin >> password;
	// THIS IS NOT MADE YET
	// checkPassword();
	// The following doesn't really follow how maps work... 
	// Try with map.find() != map.end, ->first returns the key (user) and ->second returns value (password)
	//for(int i = 0; i < 100; i++) {
	//	if(user == users[i][0] && password == &users[i][1]) {
	//		// Question: Why will priv be a two dimenstional array? 
	//		// priv = users[i][2];
	//		// return 1;
	//	}
	//}

	cout << "Incorrect username/password combination. Please enter correct information." << endl;
	cout << "Note: If you do not have a username and password, please contact your administrator for this system." << endl;
	login();
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

void priv::setUserName() {
	cout << "Please enter you username: " << endl;
	string tempUsername;
	cin >> tempUsername;
	cout << "Please confirm your username: " << endl;
	string tempUsername2;
	cin >> tempUsername2;
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

void priv::setPassword() {
	cout << "Please enter your password: " << endl;
	string tempPassword;
	cin >> tempPassword;
	cout << "Please confirm your password: " << endl;
	string tempPassword2;
	cin >> tempPassword2;

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
	cout << "Set Privilege Level: " << endl;
	cout << "\t" << "1. Read-Only" << endl;
	cout << "\t" << "2. Read and Modify" << endl;
	cout << "\t" << "3. Full/Administrative Access" << endl;
	int privlevel;
	cin >> privlevel;
	if (privlevel == 1) {
		auth = 1;
		// filePrivs << 1;
		return;
	}
	if (privlevel == 2) {
		auth = 2;
		// filePrivs << 2;
		return;
	}
	if (privlevel == 3) {
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
