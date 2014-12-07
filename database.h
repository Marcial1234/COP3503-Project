/*
    File: database.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#ifndef DATABASE_H
#define DATABASE_H

#include "gendepend.h"
#include "employee.h"

class Database {
private:
    std::vector<Employee> records;

public:
//I'm assuming these are currently being built or will be built in the near future
void pushFiles();
void pullFiles();
    bool newFile(std::string filename);
    bool loadEmployee(std::string filename);
    bool deleteEmployee(Employee worker);
    void checkAuth();
    void addEmployee(Employee worker);
    void printRecord(Employee worker);

};
#endif // Database_h
