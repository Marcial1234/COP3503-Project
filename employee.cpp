#include "employee.h"
#include "perf.h"

using namespace std;

Employee::Employee() {

	cout << "Please fill out employee information" << endl;
	cout << "Information can be changed at any time if necessary" << endl;

	setName();
	setAge();
	setSalary();
	setOccupation();
	setHashSSN();

	cout << "Is the employee new? (Y/N)" << endl;
	char input;
	cin >> input;

	if (tolower(input) == 'n') {
		setHoursWorkedWeek();
		setHoursWorkedMonth();
		setRaise();
		// if setRaise() is true, setRaiseValue will be called
		// setRaiseValue();
		setInsurance();
		// if Insurance is true, setInsurance() calls setInsurancePlan()
		// setInsurancePlan();
		// setPerformanceReport() is handled by the performance report class (perf.cpp)
		// setPerformanceReport();
		setComment();
	}

	cout << "Note: Make sure to update employee information on a regular basis." << endl;
}

// Again the issue of 'value.length', defaulted to string in this case since no prior type was present.
int Employee::infoCheck(string type, string value) {

	if (type == "string") {
		for(int i = 0; i < value.length(); i++) {
			if (isdigit(value.at(i)) != 0) {
				return 1;
			}
		}
	}

	if (type == "double") {
		for(int i = 0;i < value.length();i++) {
			if (isalpha(value.at(i)) != 0) {
				return 1;
			}
		}
	}

	return 0;
}

// All 'setter' functions.
void Employee::setName() {

	cout << "\n" << "Please enter the employee's name (Last, First)." << endl;
	string input;
	getline(cin,input);

	if (infoCheck("string",input) == 1) {
		cout << "One or more invalid characters was detected. Please try again." << endl;
		setName();
	}

	name = input;
}

// Problem with all the string to doubles. I will have to deal with validation on all of them later.
void Employee::setAge() {

	cout << "\n" << "Please enter the employee's age." << endl;
	// Validation needed here
	string input;
	getline(cin,input);
	
	double tempCheck = stoi(input);
	if (infoCheck("double",input) == 1 || tempCheck <= 0) {
		cout << "Please enter a valid age (no letters or other characters)" << endl;
		setAge();
	}

	age = stoi(input);
}

void Employee::setSalary() {

	cout << "\n" << "Please enter the employee's salary." << endl;
	string input;
	getline(cin,input);

	if (infoCheck("double",input) == 1 || stod(input) <= 0) {
		cout << "Please enter a valid salary (no letters or other characters)" << endl;
		setSalary();
	}

	salary = stod(input);
}

void Employee::setRaise() {

	cout << "\n" << "If your employee is marked down for a raise enter (Y) otherwise enter (N)" << endl;
	string input;
	getline(cin,input);

	if (infoCheck("string",input) == 1) {
		cout << "Please enter a valid response (no numbers or special characters)" << endl;
		setRaise();
	}

	if (input == "Y" || input == "y") {
		raise = true;
		setRaiseValue();
	} 

	else {
		raise = false;
	}
	
}
void Employee::setRaiseValue() {
	cout << "\n" << "Please enter the raise amount" << endl;
	cout << "\t" << "Note: Raise can be negative in the event of a reduction in salary" << endl;
	string input;
	getline(cin,input);
	if (infoCheck("double",input) == 1 ) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setRaiseValue();
	}
	raiseValue = stod(input);
}
void Employee::setHoursWorkedWeek() {
	cout << "\n" << "Please enter the number of hours the employee worked this week" << endl;
	string input;
	getline(cin,input);
	if (infoCheck("double",input) == 1 || stod(input) <= 0) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setHoursWorkedWeek();
	}
	hoursWorkedWeek = stod(input);
}
void Employee::setHoursWorkedMonth() {
	cout << "\n" << "Please enter the number of hours the employee worked this month" << endl;
	string input;
	getline(cin,input);

	if (infoCheck("double",input) == 1 || stod(input) <= 0) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setHoursWorkedMonth();
	}

	hoursWorkedMonth = stod(input);
}
void Employee::setTimeEmployed() {
	cout << "\n" << "Please enter the time employed (months)" << endl;
	string input;
	getline(cin,input);

	if (infoCheck("double",input) == 1 || stod(input) <= 0) {
		cout << "Please enter a valid number (no letters or other characters)" << endl;
		setTimeEmployed();
	}

	timeEmployed = stod(input);
}
void Employee::setInsurance() {

	cout << "\n" << "If your employee qualifies for company insurance enter (Y)" << endl;
	string input = "";
	getline(cin,input);

	if (infoCheck("string",input) == 1) {
		cout << "Please enter a valid response (no numbers or special characters)" << endl;
		setInsurance();
	}
	if (input == "y") {
		insurance = true;
		setInsurancePlan();
	}
	else
		insurance = false;
}

void Employee::setInsurancePlan() {
	cout << "\n" << "Please enter the name of you employee's insurance plan" << endl;
	string input;
	getline(cin,input);

	if (infoCheck("string",input) == 1) {
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

void Employee::setComment() {
	cout << "\n" << "If you have any comment's to add to the employee's record add them here" << endl;
	string input;
	getline(cin,input);
	if (infoCheck("string",input) == 1) {
		cout << "Please enter a comment" << endl;
		setComment();
	}
	comment = input;
}
void Employee::setHashSSN() {
	cout << "\n" << "Please enter the name of you employee's SSN (Social Security Number)" << endl;
	cout << "\t" << "Note: The SSN itself will not be stored, rather a hash result will be stored for later validation purposes" << endl;
	string input;
	getline(cin,input);

	if (infoCheck("double",input) == 1 || input.length() != 9) {
		cout << "Please enter a valid number" << endl;
		setHashSSN();
	}
	input = stod(input);

	// What is this?
	hashSSN = hash->getHash(input);
}
void Employee::setOccupation() {
	cout << "\n" << "Please enter the name of you employee's role in your company" << endl;
	string input;
	getline(cin,input);

	if (infoCheck("string",input) == 1) {
		cout << "Please enter a valid response" << endl;
		setOccupation();
	}

	occupation = input;
}

// All 'getter' functions
string Employee::getName() {
	return name;
}

double Employee::getAge() {
	return age;
}

double Employee::getSalary() {
	return salary;
}

bool Employee::getRaise() {
	return raise;
}

double Employee::getRaiseValue() {
	return raiseValue;
}

double Employee::getHoursWorkedWeek() {
	return hoursWorkedWeek;
}

double Employee::getHoursWorkedMonth() {
	return hoursWorkedMonth;
}

double Employee::getTimeEmployed() {
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

double Employee::getHashSSN() {
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

//other variable management functions
void payEmployee();
