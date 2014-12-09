#pragma once
/*
    File: perf.h
    Author: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 5, 2014
*/

#include "gendepend.h"

class EmployeeReport {

private:
    // Sets the employee's name for the performance report.
	std::string name;
	// Sets the employee's attendance grade for the performance report.
    std::string attendance;
    // Sets the employee's leadership ability for the performance report.
    std::string leadershipAbility;
    // Sets the employee's work quality for the performance report.
    std::string workQuality;
    // Sets the employee's communication grade for the performance report.
    std::string communication;
    // Sets the employee's organization for the performance report.
    std::string organization;
    // Sets the employee's responsibility for the performance report.
    std::string responsibility;
    // Sets the employee's time management skills for the performance report.
    std::string timeManagement;
    // Sets the employee's additional comments for the performance report.
    std::string additionalComments;

public:
	EmployeeReport(std::string employeeFile, int reportNumber);
    // Ain't needed. Should be handled by validation.
	int checkUserAuthorization();
};
