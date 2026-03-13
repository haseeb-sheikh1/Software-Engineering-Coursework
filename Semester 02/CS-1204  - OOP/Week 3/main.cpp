#include<iostream> // including i/o stream library
#include<iomanip>  // including iomanip  library
#include"BankAccount.h" // including header file Bank-Account
#include"UpdatedBankAccount.h" // including header file Updated-Bank-Account
#include"Person.h" // including header file Person
#include"Student.h" // including header file Student
#include"Shape.h" // including header file Shape
#include"Rectangle.h" // including header file Rectangle
using namespace std; // using standard namespace
// main function
int main (){
	//                                              LAB {WEEK # 3 DATED: 2 MAY 2025}
	//                                        TASK NUMBER 1 {COPY CONSTRUCTOR - SHALLOW COPY}
	//                                            working with the class BANK-ACCOUNT
	
	BankAccount account1(1000); // Original account
    BankAccount account2 = account1; // Creating shallow copy
    // using stream manipulators to format output
    cout << setfill(' ') << right << setw (65) << "Before modification:" << endl;
    account1.displayBalance(); // method to display balance
    account2.displayBalance();

    account2.setBalance(5000); // Modifying copied object
    // using stream manipulators to format output
    cout << setfill(' ') << right << setw (69) << "After modifying account2:" << endl;
    account1.displayBalance(); //  both should reflect change / Unexpected bahaviour
    account2.displayBalance(); //  // Both account1 and account2 go out of scope, destructors are triggered twice!
    
    
    
    //                                        TASK NUMBER 2 {COPY CONSTRUCTOR - DEEP COPY}
	//                                         working with the class UPDATED-BANK-ACCOUNT

	
	UpdatedBankAccount account1(1000); // Original account
    UpdatedBankAccount account2 = account1; // Creating deep copy
    // using stream manipulators to format output
    cout << setfill(' ') << right << setw (65) << "Before modification:" << endl;
    account1.displayBalance();
    account2.displayBalance();
    
    account2.setBalance(5000); // Modifying copied object
    // using stream manipulators to format output
    cout << setfill(' ') << right << setw (69) << "After modifying account2:" << endl;
    account1.displayBalance(); // Should remain unchanged
    account2.displayBalance(); // Should reflect change



	//                                             TASK NUMBER 3 {SINGLE INHERITANCE}
	//                                          working with the class PERSON and STUDENT
    
    // object of base class
	Person p; 
    p.setPerson("Ali", 30);
    // object of derived class
    Student s; 
    s.setStudent("ALi", 30, 101);
	p.showPerson();  // method to show details
	s.showStudent(); // method to show details



    //                                          TASK NUMBER 4 {CONSTRUCTOR IN INHERITANCE}
	//                                          working with the class SHAPE and RECTANGLE 
    
    // creating object of derived class
	Rectangle rec; // here shape (base class) constructor gets called first!
	
	return 0; 
	
}
