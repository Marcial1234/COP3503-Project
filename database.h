#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

class Database {
    public:

    bool load_employee(string filename) {
        if(ifstream(filename))
        {
            add_employee(new Employee(filename));
            return true;
        }
        return false;
    }

    void add_employee(Employee worker) {
        records.push_back(worker);
    }

    bool delete_employee(Employee worker) {
        if(ifstream(worker.file))
        {
            return ((bool)remove(worker.file) + 1);
        }
        return false;
    }

    void print_record(Employee worker) {
        cout << worker << endl;
    }

    bool new_file(string filename) {
        if(ifstream(filename))
        {
            cout << "File already exists." << endl;
            return false;
        }
        ofstream file(filename);
        if (!file)
        {
            cout << "File could not be created" << endl;
            return false;
        }
        return true;

    }

    void check_Auth();

    vector<Employee> get_records()
    {
        return this->records;
    }

    private:

    vector<Employee> records;

    protected:


};
#endif // DATABASE_H
