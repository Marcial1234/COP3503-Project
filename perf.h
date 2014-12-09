#pragma once
/*
    File: perf.h
    Author: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 5, 2014
*/

#include "gendepend.h"

class EmployeeReport {

private:
	std::string name;
    std::string attendance;
    std::string leadershipAbility;
    std::string workQuality;
    std::string communication;
    std::string organization;
    std::string responsibility;
    std::string timeManagement;
    std::string additionalComments;

public:
	EmployeeReport(std::string employeeFile, int reportNumber);
    // Ain't needed. Should be handled by validation.
	int checkUserAuthorization();
};
