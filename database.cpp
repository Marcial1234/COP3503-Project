#include "generic dependencies.h"

#include "database.h"
#include "employee.h"

bool loadEmployee(string filename) {
    if(ifstream(filename)) {
        add_employee(new Employee(filename));
        return true;
    }
    return false;
}

void addEmployee(Employee worker) {
    records.push_back(worker);
}

bool deleteEmployee(Employee worker) {
    if(ifstream(worker.file)) {
        return ((bool)remove(worker.file) + 1);
    }
    return false;
}

void printRecord(Employee worker) {
    cout << worker << endl;
}

bool newfile(string filename) {
    if(ifstream(filename)) {
        cout << "File already exists." << endl;
        return false;
    }
    ofstream file(filename);
    if (!file) {
        cout << "File could not be created" << endl;
        return false;
    }
    return true;
}

void checkAuth();
	vector<Employee> get_records() {
        return this->records;
    }

};
