
/*
    File: perf.cpp
    Author: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 5, 2014
*/

// Todo: Coordinate with Marcial and Dax on verification. May take out some extra formats.
// Todo: Implement functions in "employee.cpp" to interface with "perf.cpp".
// Todo: Implement comment system and viewing system. This probably depends on ability to save data to .txt files.
// Todo: Unforseen bug-fixes. Work on other areas of the project which need assistance.

#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

EmployeeReport() {
	cout << "Welcome to the HRSys Employee Report and Acquisition Module (HRSyS ERAM)." << endl;
	cout << "Information can be requested on any active employee." << endl;
	cout << endl;
	cout << "Please enter the employee's name, birthdate, and SSN below." << endl;
	cout << "Users with administrator privilages only need one piece of information." << endl;
	cout << endl;

	cout << "Name can be entered in one of the following two formats:" << endl;
	cout << "(1). Last, First" << endl;
	cout << "(2). First Last" << endl;
	cout << endl;

	cout << "Name: ";
	string name;
	cin >> name;
	cout << endl;

	cout << "Birthdate can be entered in one of the following three formats:" << endl;
	cout << "(1). MMDDYYYY" << endl;
	cout << "(2). MM-DD-YYYY" << endl;
	cout << "(3). MM/DD/YYYY" << endl;
	cout << endl;
    
    cout << "Birthdate: ";
	string birthdate;
	cin >> birthdate;
	cout << endl;
    
    cout << "Social Security Number can be entered in one of the following two formats:" << endl;
    cout << "(1). AAA-GG-SSSS" << endl;
    cout << "(2). AAGGSSSS" << endl;
    cout << endl;
    
	string social_security;
	cout  << "SSN: ";
    cin >> social_security;
    cout << endl;
}
