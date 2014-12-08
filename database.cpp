#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

bool Database::loadEmployee(string filename) {

    if (ifstream(filename)) {
        addEmployee(*(new Employee()));
        return true;
    }
    else
        return false;
}

void Database::addEmployee(Employee worker) {

    records.push_back(worker);
}

bool Database::deleteEmployee(string filename) {
    if (remove (filename) != 0) {
        perror("Error deleting file");
        return false;
    } else {
        return true;
    }
    return false;
}

void Database::printRecord(Employee worker) {
	worker.printEmployeeRecords();
}

void Database::printAllRecords(vector<Employee> employee_records) {

	for (int i = 0; i != employee_records.size(); i++ ) {
		printRecord(employee_records.at(i));
	}
}

bool Database::newFile(string filename) {

    if (ifstream(filename)) {
        cout << "File already exists." << endl;
        return false;
    }

    ofstream file(filename);

    if (!file) {
        cout << "File could not be created" << endl;
        return false;
    }
    else 
        return true;
}
/*
int main()
{
Database o = *(new Database());
return 0;
}*/
