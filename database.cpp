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
//#include <sys/stat.h>
void Database::makeDirectory(string filename) {
	const int dir_err = mkdir("C:/", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (dir_err == -1)
	{
    		cout << "Error creating directory!" << endl;
	}
}

//#include <unistd.h>
void Database::removeDirectory(string filename) {
	const int dir_err = rmdir("C:/");
	if(dir_err == -1) {
		cout << "Error removing directory!" << endl;
	}
}
