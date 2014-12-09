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
	name = RecursivelyValidate();
	toFile << "Name: " << name << endl;

	cout << "Attendance: ";
	attendance = RecursivelyValidate();
	toFile << "Attendance: " << attendance << endl;

	cout << "Leadership Ability: ";
	leadershipAbility = RecursivelyValidate();
	toFile << "Leadership Ability: " << leadershipAbility << endl;

	cout << "Quality of Work: ";
	workQuality = RecursivelyValidate();
	toFile << "Quality of Work: " << workQuality << endl;

	cout << "Communication Skills: ";
	communication = RecursivelyValidate();
	toFile << "Communication: " << communication << endl;

	cout << "Organizational Skill: ";
	organization = RecursivelyValidate();
	toFile << "Organizational Skill: " << organization << endl;

	cout << "Responsibility: ";
	responsibility = RecursivelyValidate();
	toFile << "Responsibility: " << responsibility << endl;

	cout << "Time Management: ";
	timeManagement = RecursivelyValidate();
	toFile << "Time Management: " << timeManagement << endl;

	cout << "Additional Comments: ";
	additionalComments = RecursivelyValidate();
	toFile << "Additional Comments: " << additionalComments << endl;

	toFile.close();
}
