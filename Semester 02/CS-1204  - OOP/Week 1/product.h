#include<iostream> // including input/output stream header file
#include<iomanip> // to get stream manipulators
#include<windows.h> // to get the colour change functionality
#include<string> // including string header file
using namespace std; // using standarad namespace
// craeting a class product
class Product {
	// private data members
	private: // access specifier
		string name;
		double price;
		double quantity;

	// public setters for all fields
	public:
		void setName(string n) {
			if(!n.empty()) { // check to validate the name
				name = n;
			} else {
				SetConsoleTextAttribute(h,4); // color code for red
				cout <<"Invalid input. Name cannot be empty!" << endl;
				SetConsoleTextAttribute(h,7); // color code for white
			}
		}
		void setPrice(double p) {
			if (p>0) { // check to validate the price
				price = p;
			} else {
				SetConsoleTextAttribute(h,4); // color code for red
				cout <<"Invalid Input. Price cannot be zero or negative!" << endl;
				SetConsoleTextAttribute(h,7); // color code for white
			}
		}
		void setQuantity(double q) {
			if (q>0) { // check to validate the quantity
				quantity = q;
			} else {
				SetConsoleTextAttribute(h,4); // color code for red
				cout << "Invalid Input. Quantity cannot be zero or negative!" << endl;
				SetConsoleTextAttribute(h,7); // color code for white
			}
		}

		// getters for all fields
		string getName() {
			return name; // returning name
		}
		double getPrice() {
			return price; // returning price
		}
		double getQuantity() {
			return quantity; // returning quantity
		}
};