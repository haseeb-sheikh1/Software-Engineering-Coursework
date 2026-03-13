#include <iostream> // including input/output stream library
#include<iomanip> // including the iomanip library
#include<string> // string library
#include"Employee.h" // including the header files
#include"BankAccount.h"
#include"Rectangle.h"
#include"Locker.h"
using namespace std;

int main() {
	//                                         LAB {WEEK # 2 DATED: 25 APRIL 2025}
	//                           TASK NUMBER 1 {DEFAULT CONSTRUCTOR - EMPLOYEE MANAGEMENT SYSTEM}
	//                                          working with the class EMPLOYEE
    
    Employee emp; // Creating an object using the default constructor.
    emp.displayDetails(); // Display employee details
    
    
	//                         TASK NUMBER 2 {PARAMETERIZED CONSTRUCTOR - BANK ACCOUNT INITIALIZATION}
    //                                           working with the class BANK-ACCOUNT

    BankAccount account("PK0309800780100", "Haseeb Sheikh", 10000); // Creating a BankAccount object with predefined values.
    account.showAccountDetails();    // Display account details
   
    

    //                                         TASK NUMBER 3 {CONSTRUCTOR OVERLOADING}
    //                                             working with class RECTANGLE

    // Creating objects using different constructors
    Rectangle rect1;            // Default constructor
    Rectangle rect2(5.0f, 3.0f); // Parameterized constructor
    Rectangle rect3(4.0f);      // Square constructor

    // Displaying details of each rectangle
    rect1.display();
    rect2.display();
    rect3.display();


    //                                            TASK NUMBER 4 { DESTRUCTOR }
    //                                             working with class LOCKER
    // creating object on the stack
    cout << setfill(' ') << right << setw(68) << "Entering the block..." << endl;
    {   // Creating locker object inside a block.
	    Locker stackLocker;
    }   // Destructor automatically called when block ends
    cout << setfill(' ') << right << setw(65) << "Exited the block." << std::endl;

    // Creating object on heap
    Locker* heapLocker = new Locker;
    // Releasing memory manually
    delete heapLocker;  // Destructor explicitly called



    return 0;
}