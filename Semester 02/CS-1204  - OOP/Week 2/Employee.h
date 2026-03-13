#include<iostream> // including input/output stream library
#include<string> // including string library
using namespace std;

class Employee {
private: // access specifier
    int id;
    string name;
    float salary;

public: // access specifier
    // Default constructor
    Employee() {
        id = 0;
        name = "Not Assigned";
        salary = 0.0;
    }

    // Method to display employee details
    void displayDetails() {
    	
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: $ " << salary << endl;
    }
};

