#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "employee.h"

using namespace std;

Employee() {
	Hash newHash = new Hash();
	cout << "Please fill out employee information" << endl;
	cout << "Information can be changed at any time if necessary" << endl;
	setName();
	setAge();
	setSalary();
	setOccupation();
	setHashSSN();
	cout << "Is the employee new? (Y/N)" << endl;
	string input
	cin >> input;
	if(input == "N" || input == "n") {
		setHoursWorkedWeek();
		setHoursWorkedMonth();
		setRaise();
		//if setRaise() is true, setRaiseValue will be called
		//setRaiseValue();
		setInsurance();
		//if Insurance is true, setInsurance() calls setInsurancePlan()
		//setInsurancePlan();
		//setPerformanceReport() is handled by the performance report class (perf.cpp)
		//setPerformanceReport();
		setComment();
	}
	cout << "Note: Make sure to update employee information regularly" << endl;
}
int infoCheck(type,value) {
	if(type == "string") {
		for(int i = 0;i < value.length();i++) {
			if(isdigit(value.at(i)) != 0) {
				return 1;
			}
		}
	}
	if(type == "double") {
		for(int i = 0;i < value.length();i++) {
			if(isalpha(value.at(i)) != 0) {
				return 1;
			}
		}
	}
	return 0;
}
//all 'setter' functions
void setName() {
	cout << "\n" << "Please enter the employee's name (Last, First)" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("string",input) == 1) {
		cout << "Please enter a valid name (no numbers or special characters)" << endl;
		setName();
	}
	name = input;
}
void setAge() {
	cout << "\n" << "Please enter the employee's age" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 || strtod(input,NULL) <= 0) {
		cout << "Please enter a valid age (no letters or other characters)" << endl;
		setAge();
	}
	input = strtod(input,NULL);
	age = input;
}
void setSalary() {
	cout << "\n" << "Please enter the employee's salary" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 || strtod(input,NULL) <= 0) {
		cout << "Please enter a valid salary (no letters or other characters)" << endl;
		setSalary();
	}
	input = strtod(input,NULL);
	salary = input;
}
void setRaise() {
	cout << "\n" << "If your employee is marked down for a raise enter (Y) otherwise enter (N)" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("string",input) == 1) {
		cout << "Please enter a valid response (no numbers or special characters)" << endl;
		setRaise();
	}
	if(input == "Y" || input == "y") {
		raise = true;
		setRaiseValue();
	} else {
		raise = false;
	}
}
void setRaiseValue() {
	cout << "\n" << "Please enter the raise amount" << endl;
	cout << "\t" << "Note: Raise can be negative in the event of a reduction in salary" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 ) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setRaiseValue();
	}
	input = strtod(input,NULL);
	raiseValue = input;
}
void setHoursWorkedWeek() {
	cout << "\n" << "Please enter the number of hours the employee worked this week" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 || strtod(input,NULL) <= 0) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setHoursWorkedWeek();
	}
	input = strtod(input,NULL);
	hoursWorkedWeek = input;
}
void setHoursWorkedMonth() {
	cout << "\n" << "Please enter the number of hours the employee worked this month" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 || strtod(input,NULL) <= 0) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setHoursWorkedMonth();
	}
	input = strtod(input,NULL);
	hoursWorkedMonth = input;
}
void setTimeEmployed() {
	cout << "\n" << "Please enter the time employed (months)" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 || strtod(input,NULL) <= 0) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setTimeEmployed();
	}
	input = strtod(input,NULL);
	timeEmployed = input;
}
void setInsurance() {
	cout << "\n" << "If your employee qualifies for company insurance enter (Y)" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("string",input) == 1) {
		cout << "Please enter a valid response (no numbers or special characters)" << endl;
		setInsurance();
	}
	if(input == "Y" || input == "y" {
		insurance = true;
		setInsurancePlan();
	} else {
		insurance = false;
	}
}
void setInsurancePlan() {
	cout << "\n" << "Please enter the name of you employee's insurance plan" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("string",input) == 1) {
		cout << "Please enter a valid response (no numbers or special characters)" << endl;
		setInsurancePlan();
	}
	insurancePlan = input;
}
//setPerformanceReport will be handled by the performance report class (perf.cpp)
/*
void setPerformanceReport() {
	performanceReport = value;
}
*/
void setComment() {
	cout << "\n" << "If you have any comment's to add to the employee's record add them here" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("string",input) == 1) {
		cout << "Please enter a comment" << endl;
		setComment();
	}
	comment = input;
}
void setHashSSN() {
	cout << "\n" << "Please enter the name of you employee's SSN (Social Security Number)" << endl;
	cout << "\t" << "Note: The SSN itself will not be stored, rather a hash result will be stored for later validation purposes" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("double",input) == 1 || input.length() != 9) {
		cout << "Please enter a valid number" << endl;
		setHashSSN();
	}
	input = strtod(input,NULL);
	hashSSN = newHash.getHash(input);
}
void setOccupation() {
	cout << "\n" << "Please enter the name of you employee's role in your company" << endl;
	string input;
	cin.getline(input,25);
	if(infoCheck("string",input) == 1) {
		cout << "Please enter a valid response" << endl;
		setOccupation();
	}
	occupation = input;
}
//all 'getter' functions
string getName() {
	return name;
}

double getAge() {
	return age;
}

double getSalary() {
	return salary;
}

bool getRaise() {
	return raise;
}

double getRaiseValue() {
	return raiseVaule;
}

double getHoursWorkedWeek() {
	return hoursWorkedWeek;
}

double getHoursWorkedMonth() {
	return hoursWorkedMonth;
}

double getTimeEmployed() {
	return timeEmployed;
}

bool getInsurance() {
	return insurance;
}

string getInsurancePlan() {
	return insurancePlan;
}

double getPerformanceReport() {
	return performanceReport;
}

string getComment() {
	return comment;
}

double getHashSSN() {
	return hashSSN;
}

string getOccupation() {
	return occupation;
}

//all 'print' functions
void printName() {
	cout << name << endl;
}

void printAge() {
	cout << age << endl;
}

void printSalary() {
	cout << salary << endl;
}

void printRaise() {
	cout << raise << endl;
}

void printRaiseValue() {
	cout << raiseValue << endl;
}

void printHoursWorkedWeek() {
	cout << hoursWorkedWeek << endl;
}

void printHoursWorkedMonth() {
	cout << hoursWorkedMonth << endl;
}

void printTimeEmployed() {
	cout << timeEmployed << endl;
}

void printInsurance() {
	cout << insurance << endl;
}

void printInsurancePlan() {
	cout << insurancePlan << endl;
}

void printPerformanceReport() {
	for(int i = 0; i < performanceReport;i++) {
		
	}
}
void printComment() {
	cout << comment << endl;
}

void printHashSSN() {
	cout << hashSSN << endl;
}

void printOccuption() {
	cout << occuapation << endl;
}

//other variable management functions
void payEmployee();
