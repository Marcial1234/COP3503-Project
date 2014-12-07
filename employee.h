/*
	File: Employee.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "gendepend.h"
#include "hash.h"

class Employee{

private:
	std::string name;
	int age;
	double salary;
	double hashSSN;
	double timeEmployed;
	double hoursWorkedWeek;
	double hoursWorkedMonth;
	bool insurance;
	std::string insurancePlan;
	Hash * hash;

	// A brief description of an employee's role in a company. 
	std::string occupation;
	// True if employee is due for raise. False if not.
	bool raise;
	// The amount the employee's raise will be.
	double raiseValue;
	// The comment recorded on a specific employee report.
	std::string comment;
	// The number of recorded performance reports for a specific employee.
	int performanceReport;

public:
	Employee();

	// infoCheck() ensures valid information is entered.
	int infoCheck(std::string type, std::string value);

	// All 'setter' functions.
	void setAge();
	void setName();
	void setRaise();
	void setSalary();
	void setComment();
	void setHashSSN();
	void setInsurance();
	void setOccupation();
	void setRaiseValue();
	void setTimeEmployed();
	void setInsurancePlan();
	void setHoursWorkedWeek();
	void setHoursWorkedMonth();
	void setPerformanceReport();

	// All 'getter' functions.
	bool getRaise();
	bool getInsurance();
	std::string getName();
	std::string getComment();
	std::string getOccupation();
	std::string getInsurancePlan();
	double getAge();
	double getSalary();
	double getHashSSN();
	double getRaiseValue();
	double getTimeEmployed();
	double getHoursWorkedWeek();
	double getHoursWorkedMonth();
	double getPerformanceReport();

	// All 'print' functions.
	void printAge();
	void printName();
	void printRaise();
	void printSalary();
	void printComment();
	void printHashSSN();
	void printOccuption();
	void printInsurance();
	void printRaiseValue();
	void printTimeEmployed();
	void printInsurancePlan();
	void printHoursWorkedWeek();
	void printHoursWorkedMonth();
	void printPerformanceReport();

	// Other variable management functions.
	void payEmployee();
};

#endif