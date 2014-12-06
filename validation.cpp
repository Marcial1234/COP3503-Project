#include "validation.h"

using namespace std;

// Possible list of enums to link back and forth to functions
// But most likely will be replaced by function pointers
// Array of max values of submenus somewhere

int maxValue[] = { 999 };

/****************************************************************************
		End of not really serious code, begin of 80% working code
****************************************************************************/

// "Globals"
enum Privs { Read, Write, Admin };
int maxPrivValues[3] = { 1, 2, 4 };
Privs auth = Read;

string mainMenu[3][3] =
{
	// For now there's empty spots that'll be handled later.

	// Read Menu
	{
		"Browse", "", "", ""
	},
	// Read & Write
	{
		"Browse", "Edit", "", ""
	},
	// Admin
	{
		"Browse", "Edit", "Build", "Go to Settings"
	},
};

string mainMenu[3] =
{
	"Browse", "Edit", "Build", "Go to Settings"
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

enum MenuOptions
{
	Browse,
	Edit,
	Build,
	Settings
};

void (*functptrMainMenu[])() = { Browse, Edit, Build, Settings };

enum SettingsMenuOptions
{
	SetHash,
	SetCrypt,
	ChangePriv,
};

enum EditMenuOptions
{
	List,
	Move,
	AddFile, // Meh...
	AddEmployee,
	ViewEmployee,
	DeleteEmployee,
	AddFolder,
	EditFolder,
	DeleteFolder,
};

void (*functptrEdit[])() = { Rename, EditEmployee,  };
void (*functptrSettings[])() = { Browse, Edit, Build, Settings };

// Shouldn't Build just be "Build Everything"?
void (*functptrBuild[])() = { Browse, Edit, Build, Settings };

void mainMenu() {
	
	cout << "Please type one of the following:" << endl;

	// Printing custom Menu based on authorization type
	// Could turn into a method and pass diff values to it, and end/go back
	for (int i = 0; i < maxValues[auth]; ++i)
		cout << i << ": To " << mainMenu[user][i] << endl;

	cout << maxValues[auth] + 1 << ": To Exit" << endl;

	// Asking for user input
	int whatToDo = RecursivelyValitate(maxValues[auth]);

	// Array of function pointers to the desired 'whatToDo' function
	void (*functionPointerArr[whatToDo])();
}

void Browse(){
	return hello;
}

void Edit(){
	return hello;
}

void Build(){
	return hello;
}

void Settings(){
	return hello;
}


// void ClearCin() {
// 	ClearCin();
// }

// Me will buy transporation later
