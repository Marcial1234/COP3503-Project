#pragma once
#include "perf.h"
#include "perf.cpp"
#include "validation.h"
#include "validation.cpp"
#include "employee.h"

using namespace std;

string tempstring;

Employee::Employee(string workerFile) {
	tempstring = workerFile + ".txt";
	
	cout << "Please fill out employee information." << endl;
	cout << "Information can be changed at any time if necessary." << endl;

	setName();
	setAge();
	setSalary();
	setOccupation();
	setHashSSN();

	setHoursWorkedWeek();
	setHoursWorkedMonth();
	setRaise();
		// if setRaise() is true, setRaiseValue will be called
		// setRaiseValue();
	setInsurance();
		// if Insurance is true, setInsurance() calls setInsurancePlan()
		// setInsurancePlan();
	setTimeEmployed();
		// setPerformanceReport() is handled by the performance report class (perf.cpp)
		// setPerformanceReport();
	setComment();
	
	cout << "Note: Make sure to update employee information on a regular basis." << endl;
}

// All 'setter' functions.
void Employee::setName() {

	cout << "\n" << "Please enter the employee's name (Last, First)." << endl;
	string input;
	getline(cin,input);
	name = input;
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Name: " << input << endl;
}

void Employee::setAge() {

	cout << "\n" << "Please enter the employee's age." << endl;
	 // That's pretty high for an age.
	int input = RecursivelyValidate(1024);
	age = input;
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Age: " << to_string(input) << endl;
}

void Employee::setSalary() {

	cout << "\n" << "Please enter the employee's salary." << endl;
	// For the billionaires and stuff.
	long long int input = RecursivelyValidate(9223372036854775807);

	salary = input;
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Salary: " << to_string(input) << endl;
}

void Employee::setRaise() {

	string instructions = "\nIs your employee is marked for a raise?";
	vector<string> options = { "No", "Yes" };
	printGenericMenu(instructions, options);
	int input = RecursivelyValidate(options.size());

	// 0 == false, 1 == true.
	raise = input;
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Raise (y/n?): " << input << endl;
	
	if (input) 
		setRaiseValue();
}

void Employee::setRaiseValue() {

	cout << "\n" << "Please enter the raise amount." << endl;
	// Marcial: Can't handle negatives at the momement.
	// cout << "\t" << "Note: Raise can be negative in the event of a reduction in salary" << endl;
	
	
	raiseValue = RecursivelyValidate(9223372036854775807);
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "RaiseAmount: " << to_string(raiseValue) << endl;
}

void Employee::setHoursWorkedWeek() {

	cout << "\n" << "Number of hours the employee worked this week:" << endl;
	hoursWorkedWeek = RecursivelyValidate(169);
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Hours worked this week: " << to_string(hoursWorkedWeek) << endl;
}

void Employee::setHoursWorkedMonth() {

	cout << "\n" << "Number of hours the employee worked this month:" << endl;
	hoursWorkedMonth = RecursivelyValidate(5270);
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Hours worked this month: " << to_string(hoursWorkedMonth) << endl;
}

void Employee::setTimeEmployed() {

	cout << "\n" << "Enter the time employed (months):" << endl;
	timeEmployed = RecursivelyValidate(1212);
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Time employed: " << to_string(timeEmployed) << endl;
}

void Employee::setInsurance() {

	vector<string> options = { "No", "Yes" };
	printGenericMenu("\nDoes your employee qualify for company insurance?", options);
	
	int input = RecursivelyValidate(options.size());
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Insurance: " << to_string(input) << endl;
	
	if (input)
		setInsurancePlan();
}

void Employee::setInsurancePlan() {

	cout << "\n" << "Please enter the name of your employee's insurance plan:" << endl;
	string input;
	ClearCin();
	getline(cin,input);
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Insurance Plan" << input << endl;

	insurancePlan = input;
}

//setPerformanceReport will be handled by the performance report class (perf.cpp)
/*
void setPerformanceReport() {
	performanceReport = value;
}
*/

void Employee::setComment() {

	cout << "\n" << "If you have any comments to add to the employee's record, add them here:" << endl;
	string input;
	ClearCin();
	getline(cin,input);
	comment = input;
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Comments: " << input << endl;
}

void Employee::setHashSSN() {

	cout << "\n" << "Please enter the name of your employee's SSN (Social Security Number)" << endl;
	cout << "Note: The SSN itself will not be stored. Rather, a hash result will be stored for later validation purposes." << endl;
	long long int input = RecursivelyValidate(10000000000);

	hash<int> hash_fn;
	size_t str_hash = hash_fn(input);
	hashSSN = str_hash;
	
	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "HashSSN: " << to_string(hashSSN) << endl;
}

void Employee::setOccupation() {
	cout << "\n" << "Please enter the name of you employee's role in your company." << endl;
	string input;
	ClearCin();
	getline(cin,input);
	// Try breaking it and see if validation is needed.

	ofstream workerFile (tempstring,ios_base::app);
	workerFile << "Job: " << input << endl;

	occupation = input;
}

// All 'getter' functions
string Employee::getName() {
	return name;
}

long long int Employee::getAge() {
	return age;
}

long long int Employee::getSalary() {
	return salary;
}

bool Employee::getRaise() {
	return raise;
}

long long int Employee::getRaiseValue() {
	return raiseValue;
}

long long int Employee::getHoursWorkedWeek() {
	return hoursWorkedWeek;
}

long long int Employee::getHoursWorkedMonth() {
	return hoursWorkedMonth;
}

long long int Employee::getTimeEmployed() {
	return timeEmployed;
}

bool Employee::getInsurance() {
	return insurance;
}

string Employee::getInsurancePlan() {
	return insurancePlan;
}

double Employee::getPerformanceReport() {
	return performanceReport;
}

string Employee::getComment() {
	return comment;
}

long long int Employee::getHashSSN() {
	return hashSSN;
}

string Employee::getOccupation() {
	return occupation;
}

//all 'print' functions
void Employee::printName() {
	cout << name << endl;
}

void Employee::printAge() {
	cout << age << endl;
}

void Employee::printSalary() {
	cout << salary << endl;
}

void Employee::printRaise() {
	cout << raise << endl;
}

void Employee::printRaiseValue() {
	cout << raiseValue << endl;
}

void Employee::printHoursWorkedWeek() {
	cout << hoursWorkedWeek << endl;
}

void Employee::printHoursWorkedMonth() {
	cout << hoursWorkedMonth << endl;
}

void Employee::printTimeEmployed() {
	cout << timeEmployed << endl;
}

void Employee::printInsurance() {
	cout << insurance << endl;
}

void Employee::printInsurancePlan() {
	cout << insurancePlan << endl;
}

void Employee::printPerformanceReport() {
	for(int i = 0; i < performanceReport;i++) {
		
	}
}

void Employee::printComment() {
	cout << comment << endl;
}

void Employee::printHashSSN() {
	cout << hashSSN << endl;
}

void Employee::printOccuption() {
	cout << occupation << endl;
}

//Function to print info of Employee
void Employee::printEmployeeRecords() {
	ofstream workerFile (tempstring,ios_base::app);
	printAge();
	printName();
	printRaise();
	printSalary();
	printComment();
	printHashSSN();
	printOccuption();
	printInsurance();
	printRaiseValue();
	printTimeEmployed();
	printInsurancePlan();
	printHoursWorkedWeek();
	printHoursWorkedMonth();
	printPerformanceReport();
}
//other variable management functions
// void payEmployee();

