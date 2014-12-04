/*
    File: Database.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#ifndef Database_H
#define Database_H
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

class Database {
private:

    vector<Employee> records;

public:
    bool loadEmployee(string filename);
    void addEmployee(Employee worker);
    bool deleteEmployee(Employee worker);
    void printRecord(Employee worker);
    bool newFile(string filename);
    void checkAuth();

};
#endif // DATABASE_H
