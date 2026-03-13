#include<iostream>
using namespace std;
//                                                       PURE VIRTUAL FUNCTIONS

class Shape {
	public:
		virtual double Area() = 0; // Pure virtual function
};

class Rectangle : public Shape {
	private:
		double length;
		double width;

	public:
		Rectangle(double length, double width) : length(length), width(width) {}

		double Area() override {
			return length * width;
		}
};

class Circle : public Shape {
	private:
		double radius;

	public:
		Circle(double radius) : radius(radius) {}

		double Area() override {
			return 3.14 * radius * radius;
		}
};

