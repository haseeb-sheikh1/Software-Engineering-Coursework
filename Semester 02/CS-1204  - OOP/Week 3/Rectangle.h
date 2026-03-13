#include<iostream>
using namespace std;
class Rectangle : public Shape { // derived class
	public: // access specifier
		// constructor of derived class
		Rectangle() {
			cout << "Rectangle constructor called." << endl;
		}
};