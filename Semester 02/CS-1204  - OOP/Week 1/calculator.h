#include<iostream> // including input/output sream header file
#include<iomanip> // to get stream manipulators
#include<conio.h>  // including conio.h header file
#include<windows.h> // to get functions like clear screen
using namespace std; // using standard namespace
// creating a clss calculator
class Calculator {
	private: // access specifier
		int num1, num2;
		char op;
		// Function Definations.
		// Addition Function
		int addition() {
			return num1+num2;
		}
		// Subtraction Function
		int subtraction() {
			return num1-num2;
		}
		// Multiplication Function
		int multiplication() {
			return num1*num2;
		}
		// Division Function
		int division() {
			return num1/num2;
		}
	public:
		// the actual working of the calculator
		void setData() {
			while (true) {
				bool choice;
				cout << setfill(' ') <<right<<setw(65)<<"CALCULATOR"<<endl;
				cout << "Enter 1 for two numbers and 0 for three: ";
				cin >> choice;
				if(choice) {
					cout << "Input Classically (2+2)" << endl;
					cin >> num1 >> op >> num2; // Classic Input.
					switch (op) {
						case '+':
							cout << addition();
							cout << "\nPress any key to clear Screen: ";
							getch();
							system("cls"); // To Clear the Screen
							break;
						case '-':
							cout << subtraction();
							cout << "\nPress any key to clear Screen: ";
							getch();
							system("cls");
							break;
						case '*':
							cout << multiplication();
							cout << "\nPress any key to clear Screen: ";
							getch();
							system("cls");
							break;
						case '/':
							cout << division();
							cout << "\nPress any key to clear Screen: ";
							getch();
							system("cls");
							break;
						default: // If No Case Matches.
							SetConsoleTextAttribute(h,4);
							cout << "Not Valid Operation!" <<endl;
							SetConsoleTextAttribute(h,7);
							cout << "\nPress any key to clear Screen: ";
							getch();
							system("cls");
							break;
					}
				} else {
					SetConsoleTextAttribute(h,4);
					cout <<"Three number operations not available!" << endl;
					SetConsoleTextAttribute(h,7);
					cout << "\nPress any key to clear Screen: ";
					getch();
					system("cls");
				}
			}
		}
};