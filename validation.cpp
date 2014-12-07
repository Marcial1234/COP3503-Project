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

string mainMenu[4] =
{
	"Browse", "Edit", "Build", "Go to Settings"
};

enum SettingsMenuOptions
{
	SetHash,
	SetCrypt,
	ChangePriv,
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
	if ((cin >> input) && ValidateRange(input, max))
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

//void (*functptrEdit[])() = { Rename, EditEmployee,  };
void (*functptrSettings[])() = { Browse, Edit, Build, Settings };

// Shouldn't Build just be "Build Everything"?
void (*functptrBuild[])() = { Browse, Edit, Build, Settings };

void printMenu() {
	
	cout << "Please type one of the following:" << endl;

	// Printing custom Menu based on authorization type
	// Could turn into a method and pass diff values to it, and end/go back
	for (int i = 0; i < maxPrivValues[auth]; ++i)
		cout << i << ": To " << mainMenu[i] << endl;

	cout << maxPrivValues[auth] + 1 << ": To Exit" << endl;

	// Asking for user input
	int whatToDo = RecursivelyValitate(maxPrivValues[auth]);

	// Array of function pointers to the desired 'whatToDo' function
	// Go die arrays and ur const values.....
	// void (*functionPointerArr[whatToDo])();
}

// void ClearCin() {
// 	ClearCin();
// }