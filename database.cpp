#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"

using namespace std;

void Database::addEmployee(string worker) {
	ofstream employeesFile ("employees.txt",ios_base::app);
	employeesFile << worker << endl;
	employeesFile.close();
	Employee worker1 = *(new Employee(worker));
}

bool Database::deleteEmployee(const char * filename) {
	string tempstring = filename += ".txt";
    if (remove(filename) != 0) 
    {
        perror("Error deleting file");
        return false;
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
		
	}
	return false;
}

void Database::listEmployees() {
		ifstream openFile ("employees.txt")
		string newstring;
		while(getline(openFile,newstring)) {
				cout << newstring << endl;
		}
	return;	
}
