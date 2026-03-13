#include <iostream>
#include <string>

using namespace std;
class Calculatorr {
	private:
		double result;
	public:
		Calculatorr() : result(0.0) {}
		void add(double a, double b) {
			result = a + b;
		}
		double getResult() const {
			return result;
		}
};

class Student {
	private:
		string name;
		// Aggregation: The Student HAS-A pointer to a shared Calculator
		Calculatorr* sharedCalculator;
	public:
		Student(string n, Calculatorr* calc) : name(n), sharedCalculator(calc) {}
		void performCalculation(double a, double b) {
			cout << name << " is using the shared calculator." << endl;
			sharedCalculator->add(a, b);
			cout << "Result for " << name << ": " << sharedCalculator->getResult() << endl;
		}
};

