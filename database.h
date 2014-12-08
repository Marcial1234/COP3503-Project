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
    std::vector<Employee> records;

// I'm assuming these are currently being built or will be built in the near future.
public:
    void pushFiles();
    void pullFiles();
    bool newFile(std::string filename);
    bool loadEmployee(std::string filename);
    bool deleteEmployee(Employee worker);
    void checkAuth();
    void addEmployee(Employee worker);
    void printRecord(Employee worker);

};
