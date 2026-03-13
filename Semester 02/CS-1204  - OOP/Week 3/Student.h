#include<iostream>
using namespace std;
class Student : protected Person { // inherited class
	private: // access specifier
		int rollNo;
	public:
		// method to set name, age and rollNumber
		void setStudent(string n,int a,int r) {
			setPerson(n, a); // Calling the method from Person class
			rollNo = r;	// setting the value of rollNumber
		}
		// method to show details
		void showStudent() {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Roll Number: " << rollNo << endl;
		}
};