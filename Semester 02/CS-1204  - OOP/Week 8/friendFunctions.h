//                                                                FRIEND FUNCTIONS
#include<iostream>
using namespace std;
class Circle; // forward declaration of class
class Rectangle {
	private:
		double length;
		double width;

	public:
		Rectangle(double length, double width) : length(length), width(width) {}

		friend double Area(Rectangle r, Circle c); // declration of friend function

};

class Circle {
	private:
		double radius;

	public:
		Circle(double radius) : radius(radius) {}

		friend double Area(Rectangle r, Circle c); // declration of friend function
};

double Area(Rectangle r, Circle c) { // defination of friend function
	return (r.length*r.width)+(3.14 * c.radius * c.radius);
}