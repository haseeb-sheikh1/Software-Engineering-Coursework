#include<iostream>
using namespace std;
class UpdatedBankAccount {
	private: // access specifier
		double* balancePtr;
	public:
		// parameterized constructor
		UpdatedBankAccount (double bal) {
			balancePtr = new double (bal); // dynamically allocating memory
			cout << "Constructor called. Memory allocated at: " << balancePtr << endl;
		}
		// copy constructor
		UpdatedBankAccount (const UpdatedBankAccount & original) {
			balancePtr = new double (*original.balancePtr); // Creating a separate copy of balancePtr
		}
		// to modify balance
		void setBalance(double newBalance) {
			*balancePtr = newBalance;
		}
		void displayBalance () {
			cout << "Balance: $" << *balancePtr << endl;
		}
		// Destructor
		~UpdatedBankAccount () {
			delete balancePtr;
			cout << "Destructor called for memory at: " << balancePtr << endl;
		}

};