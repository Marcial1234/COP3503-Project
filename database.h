/*
    File: Database.h
    Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
    Submitted: December 8, 2014
*/

#ifndef database_h
#define database_h

class Database {
private:

    vector<Employee> records;

public:
    bool newFile(string filename);
    bool loadEmployee(string filename);
    bool deleteEmployee(Employee worker);
    void checkAuth();
    void addEmployee(Employee worker);
    void printRecord(Employee worker);

};
#endif // Database_h
