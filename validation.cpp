// Headers and includes go somewhere in here
#include "validation.h"
// Possible list of enums to link back and forth to functions
// But most likely will be replaced by function pointers
enum MenuOptions
{
	Browse,
	Edit,
	Build,
	Settings
};

enum SettingsMenuOptions
{
	SetHash,
	SetCrypt,
	ChangePriv,
};

enum BuildMenuOptions
{
	Move,
	List,
	ViewEmployee,
	// Edit ends here
	AddEmployee,
	DeleteEmployee,
	AddFile,
	AddFolder,
	DeleteFolder,
};

// array of max values of submenus somewhere
int maxValue[] = { 999 };

/****************************************************************************
		End of not really serious code, begin of 80% working code
****************************************************************************/

// "Globals"
enum Privs { Read, Write, Admin };

Privs auth = Read;

string mainMenu[3][3] =
{
	// Read Menu
	{
		"Browse"
	},
	// Read & Write
	{
		"Browse", "Edit"
	},
	// Admin
	{
		"Browse", "Edit", "Build", "Go to Settings"
	},
};

const string invalid = "\nSorry, that was an invalid input, try again\n";

// End of "Globals"

bool ValidateRange(int input, int max) {
	// Use of Discrete right here
	return max >= input && input >= 0;
}

void SpitOutStupidity() {
	cout << invalid << endl;
	cin.clear();
	cin.ignore(1024, '\n');
}

int RecursivelyValitate(int max) {
	int input = 0;

	// *Cross Fingers*
	if (getline(cin, input) && ValidateRange(input, max))
		return input;
	else
	{
		SpitOutStupidity();
		return RecursivelyValitate(max);
	}
}

void mainMenu() {
	cout << "Please type one of the following: " << endl;

	// From 0 to the 'last' array element on that dimention 
	// (not sure if the demiention spesific thing works)
	for (int i = 0; i < arr[auth].size()-1; ++i)
		cout << i << ": To " << mainMenu[user][i] << endl;
	cout << arr[auth].size() << ": To Exit" << endl;

	// max not really defined... check "maxValues" array
	int whatToDo = RecursivelyValitate(max);

	// Array of function pointers to the desired 
	(*functionPointerArr[whatToDo])();
}

// void ClearCin() {
// 	ClearCin();
// }
