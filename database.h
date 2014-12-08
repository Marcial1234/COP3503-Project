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

public:
    void pushFiles();
    void pullFiles();
    bool newFile(std::string filename);
    bool loadEmployee(std::string filename);
    bool deleteEmployee(std::string filename);
    void addEmployee(Employee worker);
    void printRecord(Employee worker);
    void printAllRecords(std::vector<Employee> worker);

};
