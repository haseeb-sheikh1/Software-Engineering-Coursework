#include <iostream>
#include <string>
using namespace std;

// Base Class: Employee2
// Represents a generic employee with name and salary attributes
class Employee2 {
private:
    string name;     // Stores the employee's name
    double salary;   // Stores the employee's salary

public:
    // Setter for name with input validation
    void setName() {
        while (true) {
            cout << "Enter name: ";
            getline(cin, name);  // Reads full name including spaces

            if (!name.empty()) break;  // Valid input
            cout << "Name cannot be empty. Try again.\n";
        }
    }

    // Setter for salary with input validation
    void setSalary() {
        while (true) {
            cout << "Enter salary: ";
            cin >> salary;

            // Checks for invalid input or negative salary
            if (cin.fail() || salary < 0) {
                cin.clear();              // Clears error state
                cin.ignore(1000, '\n');   // Discards invalid input
                cout << "Invalid salary. Please enter a non-negative number.\n";
            } else {
                cin.ignore();  // Clears newline character from buffer
                break;         // Valid input
            }
        }
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Getter for salary
    double getSalary() const {
        return salary;
    }

    // Displays employee's name and salary
    void displayEmployee() const {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Derived Class 1: Developer
// Inherits from Employee2 and adds programming language attribute
class Developer : public Employee2 {
private:
    string programmingLanguage;  // Stores the developer's primary language

public:
    // Setter for programming language with input validation
    void setProgrammingLanguage() {
        while (true) {
            cout << "Enter programming language: ";
            getline(cin, programmingLanguage);

            if (!programmingLanguage.empty()) break;  // Valid input
            cout << "Programming language cannot be empty. Try again.\n";
        }
    }

    // Displays the developer's programming language
    void displayDeveloper() const {
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};

// Derived Class 2: Designer
// Inherits from Employee2 and adds design tool attribute
class Designer : public Employee2 {
private:
    string designTool;  // Stores the designer's preferred tool

public:
    // Setter for design tool with input validation
    void setDesignTool() {
        while (true) {
            cout << "Enter design tool: ";
            getline(cin, designTool);

            if (!designTool.empty()) break;  // Valid input
            cout << "Design tool cannot be empty. Try again.\n";
        }
    }

    // Displays the designer's tool
    void displayDesigner() const {
        cout << "Design Tool: " << designTool << endl;
    }
};