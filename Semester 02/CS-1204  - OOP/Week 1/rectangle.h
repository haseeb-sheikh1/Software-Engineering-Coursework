#include<iostream>
using namespace std;
// creating a class RECTANGLE
class rectangle {
	private: // access specifier
		int length;
		int width;

	public:
	    // method declarations
		void setDimensions(); // setter
		void area(); // to calculate the area
		void perimeter(); // calculating perimeter
};
// methods defination outside the box
void rectangle::setDimensions() { // using the scope resolution operator
	cout << setfill(' ') <<right<<setw(65)<<"INPUT"<<endl;
	cout << "Enter Length: ";
	cin >> length;
	cout << "Enter Width: ";
	cin >> width;
}
void rectangle::area() {
	cout << setfill(' ') <<right<<setw(65)<<"OUTPUT"<<endl;
	cout << "Area: " << length * width << endl;
}
void rectangle::perimeter() {
	cout << "perimeter: " << 2 * (length + width) << endl;
}
