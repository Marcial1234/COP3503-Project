#include "gendepend.h"
#include "database.h"
#include "database.cpp"
#include "validation.h"
#include "validation.cpp"
#include "employee.h"
#include "employee.cpp"
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
	ClearCin();
	getline(cin, input);
	return input;
}

int main() {

	string instructions = "Please choose one of the following:";
	
	vector<string> MenuOptions = 
	{
		"List All Employees",
		"View Employee",
		"Edit Employee",
		"Add Employee",
		"Delete Employee",
		"Add New User",
		"Set Cipher",
		"Set Encryption Key",
		"Performance Reports"
		// "Change User Priviledges"
		// "AddFolder",
		// "EditFolder",
		// "DeleteFolder",
	};

	int maxAdminVal = MenuOptions.size();
	int maxPrivValues[3] = { 3, 4, maxAdminVal };

	while(true) {
		// Initialization
		Database database = *(new Database());
		Priv priv = *(new Priv());
		priv.login();

		int visibility = maxPrivValues[priv.getAuth()];
		vector<string> TempMenu = MenuOptions;
		TempMenu.resize(visibility);
		vector<string> CustomMenu = TempMenu;
		CustomMenu.push_back("Exit");
		printGenericMenu(instructions, CustomMenu);
		// Asking for user input. +1 so it exits on max +1, which is Exit
		int menuOptions = RecursivelyValidate(visibility+1);

		// Based on menuOptions go to each submenu. Or Exit
		if (menuOptions < visibility)
		{
			switch (menuOptions)
			{
			case 0:
				database.listEmployees();
				break;
			case 1:
				database.viewEmployee(getEmployeeName());
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
			case 5:
				priv.setNewUser();
				break;
			case 6:
				priv.setCipher();
				break;
			case 7:
				priv.setKey();
				break;
			case 8:
				database.performanceReport(getEmployeeName());
				break;
			default:
				break;
			}
		}
		else
			break;
	}

	return 0;
}
