#pragma once
/*
    File: database.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#include "gendepend.h"
#include "employee.h"

class Database {
private:

public:
    // Print to the screen, a list of employee files.
    void listEmployees();
    // Future Implementation. void editEmployee(std::string worker);
    void addEmployee(std::string worker);
    // Delete the employee file.
    bool deleteEmployee(std::string filename);
    // View the details of an employee's file.
    void viewEmployee(std::string worker);
    // Edit the details of an employee
    void editEmployee(std::string input);
    // Returns an employee's performance repot
    void performanceReport(std::string filename);
};
