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
	//employee name
	string name;
	//employee age
	double age;
	//employee salary
	double salary;
	//true if employee is due for raise, false if not
	bool raise = false;
	//amount employee's raise wil lbe
	double raiseValue;
	//hoursWorked this week
	double hoursWorkedWeek;
	//hoursWorked this month
	double hoursWorkedMonth;
	//months employed
	double timeEmployed;
	//true if employee qualifies for company insurance
	bool insurance;
	//name of employee's company insurance plan
	string insurancePlan;
	//number of recorded performance reports
	int performanceReport;
	//comment recorded on employee record
	string comment;
	//employee SSN in secure hash form
	double hashSSN;
	//brief description of employee's role in company
	string occupation;
public:
	Employee();
	//infoCheck ensures valid information is entered
	int infoCheck(string type,string value);
	//all 'setter' functions
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
	//all 'getter' functions
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
	//all 'print' functions
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
	//other variable management functions
	void payEmployee();

};

#endif