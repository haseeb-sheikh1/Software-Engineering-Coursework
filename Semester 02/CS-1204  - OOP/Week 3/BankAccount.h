#include<iostream>
using namespace std;
class BankAccount {
	private: // access specifier
		double* balancePtr;
	public: // access specifier
		// parameterized constructor
		BankAccount (double bal) {
			balancePtr = new double (bal); // dynamically allocates memory
			cout << "Constructor called. Memory allocated at: " << balancePtr << endl;
		}
		// default copy constructor
		BankAccount (const BankAccount & original) {
			balancePtr = original.balancePtr;
		}
		// Destructor
		~BankAccount () {
			cout << "Destructor called for memory at: " << balancePtr << endl;
			delete balancePtr; //  // This will cause a runtime issue if memory is shared
		}
		// to modify balance
		void setBalance(double newBalance) {
			*balancePtr = newBalance;
		}
		// to display balance
		void displayBalance () {
			cout << "Balance: $" << *balancePtr << endl;
		}


};