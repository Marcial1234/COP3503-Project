#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

bool Database::loadEmployee() {

    if (ifstream(filename)) {
        add_employee(new Employee());
        return true;
    }
    else
        return false;
}

void Database::addEmployee(Employee worker) {

    records.push_back(worker);
}

bool Database::deleteEmployee(Employee worker) {

    if (ifstream(worker.reports)) {
        if (remove(worker.reports) == 0 ))
        	return true;
    }
    return false;
}

void Database::printRecord(Employee worker) {

    cout << worker << endl;
}

void Database::printAllRecords(vector<Employee> employee_records) {

	for (int i = 0; i != employee_records.size(); i++ ) {
		cout << employee_records.at(i); << endl;
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
