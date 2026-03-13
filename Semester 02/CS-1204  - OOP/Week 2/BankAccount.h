#include <iostream> // including input/output stream library
#include <string>   // including string library 
#include<windows.h> 
using namespace std;
// initializing console handle
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

class BankAccount {
private: // access specifier
    string accountNumber;
    string accountHolder;
    double balance;

public: // access specifier
    // Parameterized constructor
    BankAccount(string accNumber, string accHolder, double bal) {
    	// Check to ensure the correct data input
    	if (!accNumber.empty() && !accHolder.empty() && bal > 0){
		    accountNumber = accNumber;
            accountHolder = accHolder;
            balance = bal;
 
		}
		else{
			SetConsoleTextAttribute(h,4); // color code for red
		    cout << "Invalid Input" << endl;
			SetConsoleTextAttribute(h,7);  // color code for green
			
		}
    }
    // Method to display account details
    void showAccountDetails() {
    	// Again putting the chech to ensure that this method is not executed in case the data is invalid.
    	if (!accountNumber.empty() && !accountHolder.empty() && balance > 0){
           cout << "Account Number: " << accountNumber << endl;
           cout << "Account Holder: " << accountHolder << endl;
           cout << "Balance: $" << balance << endl;
        }
	}

};

