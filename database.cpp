#pragma once
#include "database.h"
#include "employee.h"
#include "priv.h"
#include "employee.cpp"
#include "priv.cpp"
#include "perf.h"
#include "perf.cpp"

using namespace std;

void Database::addEmployee(string worker) {
	ifstream employeesFiles1 ("employees.txt");
	if(employeesFiles1.is_open()) {
			string newline;
			while(getline(employeesFiles1,newline)) {
					if(worker == newline) {
						cout << "Error: " << worker << " already exists." << endl;
						return;
					}
			}
	}
	employeesFiles1.close();
	ofstream employeesFile ("employees.txt",ios_base::app);
	employeesFile << worker << endl;
	employeesFile.close();
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
			if(line1 == filename) 
			{
				openFile << " ";
			}
		}
		return false;
	}
	return true;
}

void Database::listEmployees() {
	cout << endl;
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

void Database::performanceReport(string filename) {
	int reportNumber = 1;
	ifstream employeesFiles1 ("employees.txt");
	if(employeesFiles1.is_open()) {
			string newline;
			while(getline(employeesFiles1,newline)) {
					if("Name: " == newline) {
						reportNumber++;
					}
					if(filename == newline) {
							EmployeeReport report = *(new EmployeeReport(filename,reportNumber));
							cout << endl;
							return;
					}
			}
	cout << "Error: " << filename << " does not exist." << endl;
	return;
}
}

void Database::viewEmployee(string filename) {
	cout << endl;
	ifstream employeesFiles1 ("employees.txt");
	if(employeesFiles1.is_open()) {
			string newline;
			while(getline(employeesFiles1,newline)) {
					if(filename == newline) {
						filename = filename + ".txt";
						ifstream readFile (filename);
						string newline2;
						while(getline(readFile,newline2)) {
								cout << newline2 << endl;
						}	
					}
			}
	} else {
			cout << "Error: " << filename << " does not exist." << endl;	
	}	
	return;
}


void Database::makeDirectory(string filename) {
	const int dir_err = mkdir(".\"", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (dir_err == -1)
		cout << "Error creating directory!" << endl;
}

void Database::removeDirectory(string filename) {
	const int dir_err = rmdir(".\"");
	if(dir_err == -1) 
		cout << "Error removing directory!" << endl;
}

