#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

// The database should be a map

void Database::addEmployee(string worker) {
	ofstream employeesFile ("employees.txt",ios_base::app);
	string tempstring = worker += ".txt";
	employeesFile << tempstring << endl;
    return;
}

bool Database::deleteEmployee(string worker) {
	string tempstring = worker += ".txt";
    if (remove (tempstring) != 0) {
        perror("Error deleting file");
        return false;
    } 
    fstream openFile ("employees.txt");
    string line1;
    if(openFile.is_open()) {
		while(getline(openFile,line1) {
			if(line == tempstring) {
				openFile2 << "employee removed";
			}
	}
    return false;
}
