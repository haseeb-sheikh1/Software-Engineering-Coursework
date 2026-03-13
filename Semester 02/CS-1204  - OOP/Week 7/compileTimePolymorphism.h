#include<iostream>
using namespace std;
//                                                                      OPERATOR OVERLADING
class Distance {
	private:
		double feet;
		double inches;

	public:

		Distance(double feet, double inches): feet(feet), inches(inches) {

		}
		Distance () {}

		bool operator== (const Distance &other) {
			if ((this->feet == other.feet) && (this->inches == other.inches)) {
				return true;
			} else {
				return false;
			}
		}

};
//                                                                      FUNCTION OVERLOADING

class Calculator {
	public:
		int add(int a, int b) {
			return a+b;
		}

		double add(double a, double b) {
			return a+b;
		}

		int add(int a, int b, int c) {
			return a+b+c;
		}

};