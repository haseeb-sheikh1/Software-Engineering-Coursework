#include<iostream>
#include<iomanip> // to get stream manipulators
using namespace std;
// creating a class STUDENT
class Student {
	private: // access specifier
		string name;
		int rollNumber;
		float marks;

	public: // access specifier
	    // member function to get data
		void getData() {
			cout << setfill(' ') <<right<<setw(73)<<"STUDENT RECORD SYSTEM"<<endl;
			cout << "Enter Your Name: ";
			cin >> name;
			cout << "Enter Your Roll Number: ";
			cin >> rollNumber;
			cout << "Enter Marks: ";
			cin >> marks;
		}
		// member function to display the data
		void displayData() {
			cout << setfill(' ') <<right<<setw(65)<<"OUTPUT"<<endl;
			cout << "Name: "<< name << endl;
			cout << "Roll Number: "<< rollNumber << endl;
			cout << "Marks: "<< marks<< endl;
		}
};