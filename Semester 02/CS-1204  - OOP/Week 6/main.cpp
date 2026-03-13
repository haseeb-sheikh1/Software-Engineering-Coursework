//                                                                             LAB NUMBER 7
//                                                                        DATED: 1-August-2025
//                                                                          RUNTIME POLYMORPHISM

#include <iostream>
#include"RuntimePolymorphism.h"
using namespace std;
int main() {
	// Use base class pointers to access different shapes
	Shape* shape1 = new Rectangle(10.0, 5.0);
	Shape* shape2 = new Circle(4.0);

	// The correct area() function is called at runtime
	cout << "Area of Rectangle: " << shape1->area() << endl;
	cout << "Area of Circle: " << shape2->area() << endl;

	delete shape1;
	delete shape2;
	return 0;
}