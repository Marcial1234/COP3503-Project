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
	int maxPrivValues[3] = { 3, 4, MenuOptions.size() };

	// Initialization
	Database database = *(new Database());
	Priv priv = *(new Priv());
	priv.login();

	while(true) {

		printMainMenu(priv.getAuth());
		int visibility = maxPrivValues[priv.getAuth()];
		// Asking for user input. +1 so it exits on max +1, which is Exit
		int menuOptions = RecursivelyValitate(visibility+1);

		// Based on menuOptions go to each submenu. Or Exit
		if (menuOptions != visibility)
		{
			vector<string> TempMenu = MenuOptions;
			TempMenu.resize(visibility);
			vector<string> CustomMenu = TempMenu;
			printGenericMenu(instructions, CustomMenu);
			menuOptions = RecursivelyValitate(visibility);

			// This is needed for add employee, supposedly
			//Employee oink = (*new Employee());

			switch (menuOptions)
			{
				// This is not 100% runnable
				case 0:
					// ListAllEmployees();
					break;					
				case 1:
					// ViewEmployee();
					break;					
				case 2:
					// EditEmployee();
					break;					
				case 3:
					//database.addEmployee(oink);
					break;					
				case 4:
					database.deleteEmployee("");
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
				case 8:
					// ChangeUserPriviledges();
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