#include<iostream>
#include<windows.h>
using namespace std;
// initializing console handle
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
// creating a class TEMPERATURE
class Temperature {
	public: // access specifier
		double temp;
		int choice;

		// setter
		void setData() {
			// better functionality {User can select the conversion}
			cout << setfill(' ') <<right<<setw(65)<<"TEMPERATURE CONVERTER"<<endl;
			cout << "Available Options: " << endl;
			cout << "1. Convert to Celcius" << endl;
			cout << "2. Convert to Fahrenheit" << endl;
			cout << "Your Choice: ";
			cin >> choice;
			if (choice == 1) { // check to ensure the correct conversion based on user choice
				cout << "Enter Temperature in Fahrenheit: ";
				cin >> temp;
			} else if (choice == 2) {
				cout << "Enter Temperature in Celcius: ";
				cin >> temp;
			} else {
				SetConsoleTextAttribute(h,4);
				cout << "Invalid Choice!" << endl;
				SetConsoleTextAttribute(h,7);
			}
		}

		// The actual conversion based on the selected choice
		void converter() {
			if (choice == 1) {
				temp = (temp - 32) * 5.0/9.0; // converting temperature to celsius
			} else if (choice == 2) {
				temp = (temp* 9.0/5.0) + 32; // converting to fahrenheit
			}
		}

		// Getter
		void display() {
			if (choice == 1) {
				cout << "Temperature in Celcius: " << temp <<" C";
			} else if (choice ==2) {
				cout << "Temperature in Fahrenheit: " << temp << " F";
			}

		}
};