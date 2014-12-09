#include "gendepend.h"
#include "database.h"
#include "database.cpp"
#include "validation.h"
#include "validation.cpp"
#include "employee.h"
#include "employee.cpp"
#include "hash.h"
#include "hash.cpp"
#include "perf.h"
#include "perf.cpp"
#include "priv.h"
#include "priv.cpp"
#include "crypt.h"
#include "crypt.cpp"

using namespace std;

string getEmployeeName()
{
	cout << "Please enter the employee name: " << endl;
	string input;
	cin >> input;
	return input;
}

int main() {

	string instructions = "Please choose one of the following:";
	
	vector<string> MenuOptions = 
	{
		"ListAllEmployees", // 1 All
		"ViewEmployee", // 1
		"EditEmployee", // 2
		"AddEmployee", // 3
		"DeleteEmployee", // 3
		"Setting", // 3
		"Set Hash",
		"Set Cipher",
		"Set Encryption Key",
		"Change User Priviledges"//, ""
		// "AddFolder",
		// "EditFolder",
		// "DeleteFolder",
	};
	int maxAdminVal = MenuOptions.size();
	int maxPrivValues[3] = { 3, 4, maxAdminVal };

	// Initialization
	Database database = *(new Database());
	Priv priv = *(new Priv());
	priv.login();

	while(true) {

		int visibility = maxPrivValues[priv.getAuth()];
		// Asking for user input. +1 so it exits on max +1, which is Exit
		vector<string> TempMenu = MenuOptions;
		TempMenu.resize(visibility);
		vector<string> CustomMenu = TempMenu;
		printGenericMenu(instructions, CustomMenu);
		int menuOptions = RecursivelyValitate(visibility+1);

		// Based on menuOptions go to each submenu. Or Exit
		switch (menuOptions)
		{
		case 0:
			database.listEmployees();
			break;
		case 1:
			string employeeFile = getEmployeeName();
			employeeFile = employeeFile + ".txt";
			ifstream openFile (employeeFile);
			string line9;
			if(openFile.is_open()) {
				while(getLine(openFile,line9)) {
					cout << line9;
				}	
			} else {
				cout << "Error: File could not open error." << endl;
			}
			break;
		case 2:
			database.editEmployee(getEmployeeName());
			break;
		case 3:
			database.addEmployee(getEmployeeName());
			break;
		case 4:
			database.deleteEmployee(getEmployeeName());
			break;
			// Tentative Deletion
		case 5:
			// SetHash();
			break;
		case 6:
			priv.setCipher();
			break;
		case 7:
			priv.setKey();
			break;
		default:
			break;
		}
	}

	return 0;
}
