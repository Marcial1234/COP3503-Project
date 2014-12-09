#pragma once
/*
	File: Employee.h
	Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
	Submitted: December 5, 2014
*/

#include "gendepend.h"
#include "crypt.h"

class Employee{

private:
    // Sets the employee's age.
	int age;
	// Sets the employee's insurance company status.
	bool insurance;
	// Sets the name of the employee.
	std::string name;
	// Sets the name of the employee's insurance plan.
	std::string insurancePlan;
	// Sets the employee's salary.
	long long int salary;
	// Sets the hashed SSN of the employee.
	long long int hashSSN;
	// Sets the time employed in months the employee has worked.
	long long int timeEmployed;
	// Sets the time the employee has worked this week.
	long long int hoursWorkedWeek;
	// Sets the time the employee has worked this month.
	long long int hoursWorkedMonth;

	// A brief description of an employee's role in a company. 
	std::string occupation;
	// True if employee is due for raise. False if not.
	bool raise;
	// The amount the employee's raise will be.
	long long int raiseValue;
	// The comment recorded on a specific employee report.
	std::string comment;
	// The number of recorded performance reports for a specific employee.
	int performanceReport;
	// Encryptor
	Crypt crypt;

public:
	// Constructor
	Employee(std::string worker);

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
	long long int getAge();
	long long int getSalary();
	long long int getHashSSN();
	long long int getRaiseValue();
	long long int getTimeEmployed();
	long long int getHoursWorkedWeek();
	long long int getHoursWorkedMonth();
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
	void printEmployeeRecords();
	void writeEmployeeRecords(std::string worker);
};
