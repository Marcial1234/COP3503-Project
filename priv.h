/*
    File: priv.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

class Priv {
private:
	// these are ONLY input streams (they only read).
	// Need output streams, and the file they're looking at needs to be declared later on 
	ifstream fileUsers;
	ifstream filePasswords;
	ifstream filePrivs;
	// sample output stream
	ostream usersWritter;


	ifstream fileReader;
	ostream fileWriter;

	map<string, string> users;
	map<string, int> privileges;
	string user;
	string password;
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

void priv::pullUserRecords() {
	string username;
	string password;
	int authorization;
	
	while(!fileUsers.eof()) {
		// Reading order: [username] [password] [authorization]
		fileUsers >> username;
		filePasswords >> password;
		filePrivs >> authorization;
		cout << "PARSED: " << username << " " << password << " " << authorization << "\n";
		users[username] = password;
		privileges[username] = authorization;
	}
}