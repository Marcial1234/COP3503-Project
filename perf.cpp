#pragma once
/*
File: perf.cpp
Author: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
Submitted: December 5, 2014
*/

/* Todo: Find some way to interface with "employee.cpp". 
A way to implement this would be to print the contents of the "employeeFile.txt" 
to console. Please assist by all means. This should be relatively simple.

Todo: setPerformanceReport() might actually be handled in "employee.cpp". 
From my understanding, it should call the main() in perf.cpp, which 
calls the EmployeeReport constructor. Please clarify on this.

Note: I'm planning on implmenting some very rudimentary validation checking. 
For example, the module might ask the user to try again if a field was 
left blank. Marcial, I'd appreciate any insight you have on validation.

Marcial: Read Validation.cpp
*/

#include "perf.h"
#include "gendepend.h"

using namespace std;

EmployeeReport::EmployeeReport(string employeeFile, int reportNumber) {
	employeeFile = employeeFile + ".txt";
	
	ofstream toFile(employeeFile,ios_base::app);
	toFile << "\n" << "Report: " << reportNumber << "\n";

	cout << "Employee Name: ";
	getline(cin, name);
	toFile << "Name: " << name << endl;

	cout << "Attendance: ";
	getline(cin, attendance);
	toFile << "Attendance: " << attendance << endl;

	cout << "Leadership Ability: ";
	getline(cin, leadershipAbility);
	toFile << "Leadership Ability: " << leadershipAbility << endl;

	cout << "Quality of Work: ";
	getline(cin, workQuality);
	toFile << "Quality of Work: " << workQuality << endl;

	cout << "Communication Skills: ";
	getline(cin, communication);
	toFile << "Communication: " << communication << endl;

	cout << "Organizational Skill: ";
	getline(cin, organization);
	toFile << "Organizational Skill: " << organization << endl;

	cout << "Responsibility: ";
	getline(cin, responsibility);
	toFile << "Responsibility: " << responsibility << endl;

	cout << "Time Management: ";
	getline(cin, timeManagement);
	toFile << "Time Management: " << timeManagement << endl;

	cout << "Additional Comments: ";
	getline(cin, additionalComments);
	toFile << "Additional Comments: " << additionalComments << endl;

	toFile.close();
}
