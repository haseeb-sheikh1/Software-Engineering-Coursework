#include<iostream>
using namespace std;
// creating a class VOTER
class Voter {
	private: // access specifier
		string name;
		int age;

	public:
		// method declaration
		bool isEligible();
};
// method defination outside the class
bool Voter::isEligible() {
	cout << setfill(' ') <<right<<setw(65)<<"VOTING ELIGIBILITY"<<endl;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter Age: ";
	cin >> age;
	if (age>18) { // check to validate the age
		return true;
	} else {
		return false;
	}
}