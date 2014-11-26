/*
	File: Employee.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#ifndef Employee_h
#define Employee_h

#include <iostream>
#include <cstring>
#include <string>

class Employee{

private:
	// Employee name.
	string name;
	// Employee age.
	double age;
	// Employee salary.
	double salary;
	// True if employee is due for raise. False if not.
	bool raise = false;
	// The amount the employee's raise will be.
	double raiseValue;
	// The number of hours the employee has worked this week.
	double hoursWorkedWeek;
	// The number of hours the employee has worked this month.
	double hoursWorkedMonth;
	// The number of months the employee has been employed.
	double timeEmployed;
	// Is true if the employee qualifies for insurance.
	bool insurance;
	// The name of a specific employee's insurance plan.
	string insurancePlan;
	// The number of recorded performance reports for a specific employee.
	int performanceReport;
	// The comment recorded on a specific employee report.
	string comment;
	// The hashed SSN of a specific employee.
	double hashSSN;
	// A brief description of an employee's role in a company. 
	string occupation;

public:
	Employee();

	// infoCheck() ensures valid information is entered.
	int infoCheck(string type, string value);

	// All 'setter' functions.
	void setName();
	void setAge();
	void setSalary();
	void setRaise();
	void setRaiseValue();
	void setHoursWorkedWeek();
	void setHoursWorkedMonth();
	void setTimeEmployed();
	void setInsurance();
	void setInsurancePlan();
	void setPerformanceReport();
	void setComment();
	void setHashSSN();
	void setOccupation();

	// All 'getter' functions.
	string getName();
	double getAge();
	double getSalary();
	bool getRaise();
	double getRaiseValue();
	double getHoursWorkedWeek();
	double getHoursWorkedMonth();
	double getTimeEmployed();
	bool getInsurance();
	string getInsurancePlan();
	double getPerformanceReport();
	string getComment();
	double getHashSSN();
	string getOccupation();

	// All 'print' functions.
	void printName();
	void printAge();
	void printSalary();
	void printRaise();
	void printRaiseValue();
	void printHoursWorkedWeek();
	void printHoursWorkedMonth();
	void printTimeEmployed();
	void printInsurance();
	void printInsurancePlan();
	void printPerformanceReport();
	void printComment();
	void printHashSSN();
	void printOccuption();

	// Other variable management functions.
	void payEmployee();
};

#endif