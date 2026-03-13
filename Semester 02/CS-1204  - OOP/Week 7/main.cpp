//                                                                                LAB # 7
//                                                                          DATED: 8 AUGUST 2025
//                                                                          COMPILE-TIME POLYMORPHISM
#include<iostream>
#include"compileTimePolymorphism.h"
using namespace std;
int main () {

	// operator overloaading
	Distance d1(10,20);
	Distance d2(30,33);
	bool isEqual;
	isEqual = d1==d2;

	// function overloading
	Calculator cal;
	cout << cal.add(2, 3) << endl; // 5
	cout << cal.add(2.5, 3.5) << endl; //6.0
	cout << cal.add(1, 2, 3) << endl;// 6

	return 0;

}

