#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
private:
    string name;  // Stores the name of the person
    int age;      // Stores the age of the person

public:
    bool flag;    // Indicates the validity of the most recent input

    // Default constructor initializes the validation flag
    Person() {
        flag = true;
    }

    // Setter for name with input validation
    void setName() {
        cout << "Enter Name: ";
        getline(cin, name);  // Reads full name including spaces

        if (!name.empty()) {
            flag = true;  // Valid input
        } else {
            cout << "Name cannot be empty. Please try again." << endl;
            flag = false; // Invalid input
        }
    }

    // Setter for age with input validation
    void setAge() {
        cout << "Age: ";
        cin >> age;

        if (age <= 0) {
            cout << "Age must be a positive value. Please try again." << endl;
            flag = false; // Invalid input
        } else {
            flag = true;  // Valid input
        }
    }

    // Displays the person's information
    void displayPersonInfo() {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
    }
};

// Derived class: Student inherits from Person
class Student : public Person {
private:
    int studentId;  // Stores the student's unique identifier

public:
    // Setter for student ID with input validation
    void setStudentId() {
        cout << "Enter ID: ";
        cin >> studentId;

        if (studentId < 0) {
            cout << "ID cannot be negative. Please try again." << endl;
            flag = false; // Invalid input
        } else {
            flag = true;  // Valid input
        }
    }

    // Displays the student's ID
    void displayStudentInfo() {
        cout << "Student ID: " << this->studentId << endl;
    }
};