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
    void editEmployee(std::string worker);
    void addEmployee(std::string worker);
    bool deleteEmployee(std::string filename);
    void viewEmployee(std::string worker);
    void makeDirectory(std::string filename);
    void removeDirectory(std::String filename);
};
