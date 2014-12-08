#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

// The database should be a map

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

// TODO
bool Database::deleteEmployee(string filename) {
   /* if (remove (filename) != 0) {
        perror("Error deleting file");
        return false;
    } else {
        return true;
    }*/
    return false;
}

void Database::printRecords(Employee worker) {
	worker.printEmployeeRecords();
}

void Database::printAllRecords(vector<Employee> employee_records) {

	for (int i = 0; i != employee_records.size(); i++ ) {
		printRecords(employee_records.at(i));
	}
}

bool Database::newFile(string filename) {
    ifstream stream(filename);
    if (stream) {
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

void Database::pushFiles() {
	
}

void Database::pullFiles() {
	
}
}
