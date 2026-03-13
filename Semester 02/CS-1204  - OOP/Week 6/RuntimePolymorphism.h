#include <iostream >
using namespace std;

// Base class with a virtual function
class Shape {
	public:
		virtual double area() const = 0; // Pure virtual function
		virtual ~Shape() {}
};

// Derived class 1
class Rectangle : public Shape {
	private:
		double width;
		double height;
	public:
		Rectangle(double w, double h) : width(w), height(h) {}
		// Override the virtual function
		double area() const override {
			return width * height;
		}
};

// Derived class 2
class Circle : public Shape {
	private:
		double radius;
	public:
		Circle(double r) : radius(r) {}
		// Override the virtual function
		double area() const override {
			return 3.14159 * radius * radius;
		}
};


