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

	vector<string> options = { "For Yes", "For No" };
	printGenericMenu("Is the employee new? (Y/N)", options);
	int input = RecursivelyValitate(options.size()+1);

	if (input == 0) {
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

friend ostream Employee::&operator<<(ostream &out, Employee worker)
{
	out << worker.getAge();
    out << worker.getName();
	out << worker.getSalary();
	out << worker.getComment();
	out << worker.getHashSSN();
    out << worker.getOccupation();
	out << worker.getTimeEmployed();
	out << worker.getHoursWorkedWeek();
	out << worker.getHoursWorkedMonth();
	out << worker.getPerformanceReport();
    
	if(worker.getRaise())
		worker.getRaiseValue();

	if(worker.getInsurance())
		worker.getInsurancePlan();

    return out;
}

// All 'setter' functions.
void Employee::setName() {
	cout << "\n" << "Please enter the employee's name (Last, First)." << endl;
	string input;
	getline(cin,input);

	name = input;
}

void Employee::setAge() {
	cout << "\n" << "Please enter the employee's age." << endl;
	int input = RecursivelyValitate(1024); // That's pretty high for an age.
	age = input;
}

void Employee::setSalary() {
	cout << "\n" << "Please enter the employee's salary." << endl;
	// for the billionaires and stuff
	long long int input = RecursivelyValitate(9223372036854775807);

	salary = input;
}

void Employee::setRaise() {
	string instructions = "\nIs your employee is marked down for a raise?";
	vector<string> options = { "For No", "For Yes" };
	printGenericMenu(instructions, options);
	int input = RecursivelyValitate(options.size(), instructions);

	// 0 == false, 1 == true. Go Back won't work
	raise = input;
	if (input)
		setRaiseValue();
}

void Employee::setRaiseValue() {
	cout << "\n" << "Please enter the raise amount" << endl;
	// Marcial: Can't handle negatives at the momement
	// cout << "\t" << "Note: Raise can be negative in the event of a reduction in salary" << endl;

	// For the billionaires
	raiseValue = RecursivelyValitate(9223372036854775807)
}

void Employee::setHoursWorkedWeek() {
	cout << "\n" << "Number of hours the employee worked this week:" << endl;
	hoursWorkedWeek = RecursivelyValitate(169);
}

void Employee::setHoursWorkedMonth() {
	cout << "\n" << "Number of hours the employee worked this month:" << endl;
	hoursWorkedMonth = RecursivelyValitate(5270);
}

void Employee::setTimeEmployed() {
	cout << "\n" << "Enter the time employed (months):" << endl;
	timeEmployed = RecursivelyValitate(1212);
}

void Employee::setInsurance() {
	vector<string> options = { "For Yes", "For No" };
	printGenericMenu("\nDoes your employee qualifies for company insurance?", options);

	// Hmm. Don't go back here. Back will set it to true
	if (RecursivelyValitate(options.size()))
		setInsurancePlan();
}

void Employee::setInsurancePlan() {
	cout << "\n" << "Please enter the name of you employee's insurance plan" << endl;
	string input;
	getline(cin,input);
	// Try breaking it and see if validation is needed.

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
	// Try breaking it and see if validation is needed.

	comment = input;
}

void Employee::setHashSSN() {
	cout << "\n" << "Please enter the name of you employee's SSN (Social Security Number)" << endl;
	cout << "\t" << "Note: The SSN itself will not be stored, rather a hash result will be stored for later validation purposes" << endl;
	long long int input = RecursivelyValitate(10000000000);

	// Marcial: What is this?
	hashSSN = hash->getHash(input);
}

void Employee::setOccupation() {
	cout << "\n" << "Please enter the name of you employee's role in your company" << endl;
	string input;
	getline(cin,input);
	// Try breaking it and see if validation is needed.

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

//Overloaded << operator to print the details of a Employee object
friend ostream &operator<<(ostream &out, Employee worker)
{
     out << worker.getName();
     out << worker.getOccupation();
     if(worker.getRaise())
     {
         worker.getRaiseValue();
     }
     if(worker.getInsurance())
     {
         worker.getInsurancePlan();
     }
	 out << worker.getComment();
	 out << worker.getAge();
	 out << worker.getSalary();
	 out << worker.getHashSSN();
	 out << worker.getTimeEmployed();
	 out << worker.getHoursWorkedWeek();
	 out << worker.getHoursWorkedMonth();
	 out << worker.getPerformanceReport();
     return out;
}
