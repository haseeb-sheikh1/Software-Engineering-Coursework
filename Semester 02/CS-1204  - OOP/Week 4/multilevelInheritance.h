#include <iostream>
#include <string>
using namespace std;

// Base Class: Person2
// Represents a generic person with basic attributes
class Person2 {
private:
    string name;  // Stores the person's name
    int age;      // Stores the person's age

public:
    bool flag;    // Indicates the validity of the most recent input

    // Default constructor initializes the validation flag
    Person2() {
        flag = true;
    }

    // Setter for name with input validation
    void setName() {
        cout << "Enter Name: ";
        getline(cin, name);  // Reads full name including spaces

        if (!name.empty()) {
            flag = true;  // Valid input
        } else {
            cout << "Name cannot be empty! Try Again" << endl;
            flag = false; // Invalid input
        }
    }

    // Setter for age with input validation
    void setAge() {
        cout << "Age: ";
        cin >> age;

        if (age <= 0) {
            cout << "Age cannot be zero or Negative! Try Again" << endl;
            flag = false; // Invalid input
        } else {
            flag = true;  // Valid input
        }
    }

    // Displays the person's name and age
    void displayPerson() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }
};

// Intermediate Class (Level Two): Employee
// Inherits from Person2 and adds employee-specific attributes
class Employee : public Person2 {
private:
    int employeeId;  // Stores the employee's unique identifier

public:
    // Setter for employee ID with input validation
    void setEmployeeId() {
        cout << "Enter ID: ";
        cin >> employeeId;

        if (employeeId < 0) {
            cout << "Id cannot be Negative! Try Again" << endl;
            flag = false; // Invalid input
        } else {
            flag = true;  // Valid input
        }
    }

    // Displays the employee ID
    void displayEmployee() {
        cout << "Employee ID: " << employeeId << endl;
    }
};

// Derived Class (Level Three): Manager
// Inherits from Employee and adds department-specific attributes
class Manager : public Employee {
private:
    string department;  // Stores the name of the department

public:
    // Setter for department name with input validation
    void setDepartment() {
        cout << "Enter Department Name: ";
        getline(cin, department);  // Reads full department name

        if (!department.empty()) {
            flag = true;  // Valid input
        } else {
            cout << "Name cannot be empty! Try Again" << endl;
            flag = false; // Invalid input
        }
    }

    // Displays the department name
    void displayManager() {
        cout << "Department: " << department << endl;
    }
};