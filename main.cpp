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

/*WILL NOT COMPILE*/
enum Menu
{
	Browse,
	Edit,
	Build,
	Settings
};

enum EditMenu
{
	List,
	AddFile, // Meh...
	AddEmployee,
	ViewEmployee,
	DeleteEmployee,
	// No?
	AddFolder,
	EditFolder,
	DeleteFolder,
};

enum SettingsMenu
{
	SetHash,
	SetCrypt,
	ChangePriv,
};
/*WILL NOT COMPILE*/

void printSettingsMenu(){

}

void printBuildMenu(){

}

void printBrowseMenu(){
	// JUST FUCKING DISPLAY ERRTHING
}

int main() {

	void (*foo)();
	foo = printSettingsMenu();

	vector<void (*)()> v = { foo, foo1,  };

	string instructions = "Please choose one of the following:";
	vector<string> MenuOptions = { "", "" };
	vector<string> SettingsMenuOptions = { "Set Hash?", "Set Encryption Key", "Change User Priviledges" };
	vector<string> EditMenuOptions = 
	{
		"AddEmployee",
		"ViewEmployee",
		"DeleteEmployee",
		// Double check
		"List",
		"AddFile", // Meh...
		// No Dax Said?
		"AddFolder",
		"EditFolder",
		"DeleteFolder",
	};

	// Function pointer with the preset things.

	int maxPrivValues[3] = { 1, 2, 4 };

	// Initialization
	Database database = *(new Database());
	// database.pullUserRecords;

	while(true) {

		Priv priv = *(new Priv());
		priv.login();
		printMainMenu(priv.getAuth());

		// Asking for user input. +1 so it exits on max +1, which is Exit
		int menuOptions = RecursivelyValitate(maxPrivValues[priv.getAuth()]+1);

		// Based on menuOptions go to each submenu. Or Exit
		if (menuOptions != maxPrivValues[priv.getAuth()])
		{
			/* SubMenus */
		}
		else
			break;
	}

	//database.pushUserRecords();

	return 0;
}
