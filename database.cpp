#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

void Database::addEmployee(string worker) {
	ofstream employeesFile ("employees.txt",ios_base::app);
	string tempstring = (worker += ".txt");
	employeesFile << tempstring << endl;
	employeesFile.close();
	Employee worker1 = *(new Employee(worker));
    return;
}

bool Database::deleteEmployee(string worker) {
	string tempstring = worker += ".txt";
    if (remove(tempstring) != 0) {
        perror("Error deleting file");
        return false;
    } 
    fstream openFile ("employees.txt");
    string line1;
    if(openFile.is_open()) {
		while(getline(openFile,line1)) {
			if(line1 == tempstring) {
				openFile << "employee removed";
				openFile << "employee removed";
			}
	}
    return false;
}
