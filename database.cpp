#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

void Database::addEmployee(string worker) {
	ifstream employeesFile1 ("employees.txt");
	if(employeesFile1.is_open()) {
		string newLine;
		while(getline(employeesFile1,newLine)) {
			if(newLine == worker) {
				cout << "Error:" << worker << " already exists" << endl;
				return;
			}
		}
	}
	employeesFile1.close();
	ofstream employeesFile2 ("employees.txt",ios_base::app);
	employeesFile2 << worker << endl;
	employeesFile2.close();
	Employee worker1 = *(new Employee(worker));
}

bool Database::deleteEmployee(string filename) {
	string tempstring = filename + ".txt";
    if (remove(tempstring.c_str()) != 0) 
    {
        perror("Error deleting file");
        return false;
    }
    fstream openFile ("employees.txt");
    string line1;
    if(openFile.is_open()) 
    {
	while(getline(openFile,line1))
	{
		if(line1 == tempstring) 
		{
			openFile << "employee removed";
		}
	}
	return false;
     }
	return true;
}

void Database::listEmployees() {
	ifstream openFile ("employees.txt");
	string newstring;
	while(getline(openFile,newstring))
		cout << newstring << endl;

	return;	
}

void Database::editEmployee(string input) {
	ifstream openFile ("employees.txt");
	if(openFile.is_open()) 
	{
		string line1;
		while(getline(openFile,line1)) 
		{
			if(line1 == input) 
			{
				this->deleteEmployee(input);
				this->addEmployee(input);
				return;
			}
		}
	}
}

void Database::viewEmployee(string worker) {
	string employeeFile = worker + ".txt";
	ifstream openFile(employeeFile);
	string line9;
	if (openFile.is_open()) {
		while (getline(openFile, line9)) {
			cout << line9 << endl;
		}
	}
	else {
	cout << "Error: File could not open error." << endl;
	}
}
