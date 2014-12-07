/*
    File: perf.cpp
    Author: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 5, 2014
*/

#include "perf.h"

using namespace std;

EmployeeReport::EmployeeReport(string employeeFile, string reportNumber) {
    ofstream toFile(employeeFile,ios_base::app);
    toFile << "\n" << reportNumber;

    cout << "Performance Report: " << "\n" << endl;

	cout << "Employee Name: ";
	getline(cin, name);
    toFile << "Name: " << name << endl;
    
    cout << "Attendance: ";
	getline(cin, attendance);
    toFile << "Attendance: " << attendance << endl;

	cout << "Leadership Ability: ";
	getline(cin, leadershipAbility);
    toFile << "Leadership Ability" << leadershipAbility << endl;

	cout << "Quality of Work: ";
	getline(cin, workQuality);
    toFile << "Quality of Work: " << workQuality << endl;

	cout << "Communication Skills: ";./
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
    toFile << "Additional Comments: " << additionalComments << "\n" << endl;
    
    toFile.close();
}
/*
// Example use
int main() {
    string employeeFile = "employeeFile.txt";
    string reportNumber = "report1.txt";
    EmployeeReport report = *(new EmployeeReport(employeeFile, reportNumber));

	return 0;
}
*/