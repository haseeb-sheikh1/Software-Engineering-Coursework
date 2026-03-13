//                                                                      LAB NUMBER 8
//                                                                 DATED: 16- August- 2025
//                                                       PURE VIRTUAL FUNCTIONS - FRIEND FUNCTIONS
#include<iostream>
#include"pureVirtualFunctions.h"
#include"friendFunctions.h"
using namespace std;
int main() {
	
	// pure virtual functions
	Rectangle rectangle(2,2);
	Circle circle(2);
	cout << rectangle.Area();
	
	// Friend functions
	Rectangle r(2,2);
	Circle c(2);
	cout << "Total Area: " << Area(r,c) << endl;


	return 0;
}
