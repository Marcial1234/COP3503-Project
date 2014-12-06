#include "generic dependencies.h"

#include "database.h"
#include "employee.h"

// No idea of what 'add_employee' is. File manipulation is odd later on and should be done, rather
// All the mods should be done on the local maps

bool Database::loadEmployee(string filename) {
    if(ifstream(filename)) {
        add_employee(new Employee(filename));
        return true;
    }
    return false;
}

void Database::addEmployee(Employee worker) {
    records.push_back(worker);
}

bool Database::deleteEmployee(Employee worker) {
    if(ifstream(worker.file)) {
        return ((bool)remove(worker.file) + 1);
    }
    return false;
}

void Database::printRecord(Employee worker) {
	// u high... yep
    //cout << worker << endl;
}

bool Database::newFile(string filename) {
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
