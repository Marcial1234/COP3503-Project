/*
    File: perf.cpp
    Author: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 5, 2014
*/

// Todo: Coordinate with Marcial and Dax on verification. May take out some extra formats.
// Todo: Implement functions in "employee.cpp" to interface with "perf.cpp".
// Todo: Implement comment system and viewing system. This probably depends on ability to save data to .txt files.
// Todo: Unforseen bug-fixes. Work on other areas of the project which need assistance.
#include "perf.h"

EmployeeReport::EmployeeReport() {

    string name;
    string birthdate;
    string social_security_number;
    string attendance;
    string leadership_ability;
    string quality_of_work;
    string communication_skill;
    string organizational_skill;
    string responsibility;
    string time_management;
    string team_player;
    string additional_comments;

	cout << "Welcome to the HRSys Employee Report and Acquisition Module (HRSyS ERAM)." << endl;
	cout << "Information can be requested on any active employee." << endl;
	cout << endl;

	cout << "Welcome to the HRSys Employee Report and Acquisition Module (HRSyS ERAM)." << endl;
	cout << "Information can be generated or edited for any active employee.\n" << endl;

	cout << "Name: ";
	getline(cin, name);

    cout << "Birthdate: ";
	getline(cin, birthdate);

    cout << "Social Security Number: ";
	cin >> social_security_number;
    getline(cin, social_security_number);
    
    cout << "Attendance: ";
	getline(attendance);

	cout << "Leadership Ability: ";
	getline(leadership_ability);

	cout << "Quality of Work: ";
	getline(quality_of_work);

	cout << "Communication Skill: ";
	getline(communication_skill);

	cout << "Organization Skill: ";
	getline(organizational_skill);

	cout << "Responsibility: ";
	getline(responsibility);

	cout << "Time Management: ";
	getline(time_management);

	cout << "Team Player: ";
	getline(team_player);

	cout << "Additional Comments: ";
    getline(additional_comments);
    
    //
    cout << "Name: " << name;
    cout << "Birthdate: " << birthdate;
    cout << "Social Security Number: " << social_security_number;
    cout << "\n-------------------------------\n";
    cout << "Attendance: " << attendance;
    cout << "Leadership Ability: " << leadership_ability;
    cout << "Quality of Work: " << quality_of_work;
    cout << "Communciation Skill: " << communication_skill;
    cout << "Organizational Skill: " << organizational_skill;
    cout << "Responsibility: " << responsibility;
    cout << "Time Management: " << time_management;
    cout << "Team Player: " << team_player;
    cout << "\n-------------------------------\n";
    cout << "Additional Comments: " << additional_comments;
}

// Some testing.
int main() {
	EmployeeReport(); 
	cout << "Preliminary test was a success!" << endl;
	return 0;
}
