#include<iostream>
using namespace std;
class Person {  // base class
	protected: // access specifier
		string name;
		int age;
	public:
		// method to set name and age
		void setPerson(string n,int a) {
			name = n;
			age = a;
		}
		// method to show details
		void showPerson() {
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
		}

};
