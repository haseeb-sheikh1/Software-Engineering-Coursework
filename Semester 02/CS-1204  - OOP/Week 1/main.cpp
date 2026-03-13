#include<iostream> // including input/output stream library
#include "Student.h" // linking the header file student.h 
#include "rectangle.h" // linking the header file rectangle.h
#include "Voter.h" // linking the header file voter.h
#include "Temperature.h" // linking the header file temperature.h
#include "Calculator.h" // linking the header file calculator.h
#include "Product.h" // linking the header file product.h
using namespace std; // using standard namespace
// main function
int main() {
	//                                         LAB {WEEK # 1 DATED: 18 APRIL 2025}
	//                                        TASK NUMBER 1 {STUDENT RECORD SYSTEM}
	//                                          working with the class STUDENT

	Student std;   // creating an object of class student
	std.getData(); // getting data
	std.displayData(); // displaying data

	//                                         TASK NUMBER 2 {FUNCTIONS OUTSIDE THE CLASS}
	//                                             working with the class RECTANGLE
	rectangle rec;  // obj. of type rectangle
	rec.setDimensions(); // setter
	rec.area(); // calculating area
	rec.perimeter(); // calculating perimeter

	//                                        TASK NUMBER 3 { VOTING ELIGIBILITY }
	//                                            working with the class VOTER
	Voter random; // obj. of type voter
	if (random.isEligible()) { // check to validate the age
		SetConsoleTextAttribute(h,2); // to change the font color on console
		cout << "Eligible" << endl;
		SetConsoleTextAttribute(h,7);
	} else { // if it returns the value false
		SetConsoleTextAttribute(h,4);
		cout << "Not Eligible" << endl;
		SetConsoleTextAttribute(h,7);
	}


	//                                        TASK NUMBER 4 {TEMPERATURE CONVERTER}
	//                                          working with class TEMPERATURE
	
	Temperature temper; // object of type temperature
	temper.setData(); // setter
	temper.converter(); // to convert temperature
	temper.display();  // to display the data


	//                                          TASK NUMBER 5 {CALCULATOR}
	//                                         working with class CALCULATOR
	
	Calculator cal; // object of type calculator
	cal.setData(); // contains the working of the calculator


	//                                       TASK NUMBER 6 {ENCAPSULATION}
	//                                      working with the class PRODUCT
	
	Product p; // object of class product
    p.setName(cin); // setter
	p.setPrice(-50); // setter
	p.setQuantity(-2); // setter
	
	p.setName("Laptop"); // setter
	p.setPrice(1200.50); // setter
	p.setQuantity(2); // setter

	cout << "Product: " << p.getName() << endl; // getter
	cout << "Price: $" << p.getPrice() << endl; // getter
	cout << "Quantity: " << p.getQuantity() << endl; // getter

	return 0;
}