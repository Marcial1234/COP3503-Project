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
    void listEmployees();
    void editEmployee(std::string);
    void addEmployee(std::string worker);
    bool deleteEmployee(std::string filename);
};
