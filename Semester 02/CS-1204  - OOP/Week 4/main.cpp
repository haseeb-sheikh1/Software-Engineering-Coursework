#include<iostream>
#include<string>
#include"singleInheritance.h"
#include"multilevelInheritance.h"
#include"hierarchicalInheritance.h"
#include"multipleInheritance.h"

using namespace std;
//                                                             WEEK # 4
//                                                    TOPIC: TYPES OF INHERITANCE
//                                                       DATED: 23, MAY 2025

int main (){
	
	//                                            TASK NUMBER 1( SINGLE INHERITANCE )
	
	Person p1;

    // Prompt for name input with validation loop 
    p1.setName();
    while (!p1.flag) {  // Repeats until valid name is entered
       p1.setName();
    }   

    // Prompt for age input with validation loop
    p1.setAge();
    while (!p1.flag) {  // Repeats until valid age is entered
       p1.setAge();
    }

    // Creating a Student object
    Student s1;

    // Prompt for student ID input with validation loop
    s1.setStudentId();
    while (!s1.flag) {  // Repeats until valid ID is entered
       s1.setStudentId();
    }

    // Displaying the validated personal information
    p1.displayPersonInfo();

    // Displaying the validated student-specific information
    s1.displayStudentInfo();
	/*
	
	//                                            TASK NUMBER 2 ( MULTI-LEVEL INHERITANCE )
	
	
	Manager manager;
	manager.setName();
	while (!manager.flag){ // To get the correct input (loop inCase input is incorrect)
	   manager.setName();	
	}
	manager.setAge();
	while (!manager.flag){ // To get the correct input (loop inCase input is incorrect)
		manager.setAge();	
	}
	

	manager.setEmployeeId();
	while (!manager.flag){ // To get the correct input (loop inCase input is incorrect)
		manager.setEmployeeId();	
	}
   
    manager.setDepartment();
	while (!manager.flag){ // To get the correct input (loop inCase input is incorrect)
		manager.setDepartment();	
    }
    cout << "\n--- Complete Manager Information ---" << endl;

    // Display all information using functions from all levels
    manager.displayPerson();
    manager.displayEmployee();
    manager.displayManager();
    
	
   //                                                   TASK NUMBER 3 ( HIERARCHICAL INHERITANCE ) 
   
   
    Developer dev;
    cout << "--- Enter Developer Information ---" << endl;
    dev.setName();
    dev.setSalary();
    dev.setProgrammingLanguage();

    cout << "\n--- Developer Information ---" << endl;
    dev.displayEmployee();
    dev.displayDeveloper();

    cout << "\n";

    Designer designer;
    cout << "--- Enter Designer Information ---" << endl;
    designer.setName();
    designer.setSalary();
    designer.setDesignTool();

    cout << "\n--- Designer Information ---" << endl;
    designer.displayEmployee();
    designer.displayDesigner();
    
    
    //                                                   TASK NUMBER 3 ( HIERARCHICAL INHERITANCE ) 
    
    Photocopier myDevice;
    // Input and validation
    myDevice.setDeviceName();
    myDevice.setPagesToScan();
    myDevice.setPagesToPrint();

    // Function calls
    cout << "\n--- Device Operations ---" << endl;
    
    myDevice.scanDocument();
    myDevice.printDocument();
    myDevice.startPhotocopy();
    */
	return 0;
}