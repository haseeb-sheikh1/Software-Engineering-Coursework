#include <iostream>
using namespace std;
// The Display class is a component of the Calculator
class Display {
	public:
		void showResult(double result) {
			cout << "Current Result: " << result << endl;
		}
		void showLastResult(double lastResult) {
			cout << "Last Result: " << lastResult << endl;
		}
};

class Calculator {
	private:
		// Composition: The Calculator HAS-A Display object
		Display display;
		double lastResult;

	public:
		Calculator() : lastResult(0.0) {}

		void add(double a, double b) {
			lastResult = a + b;
			display.showResult(lastResult);
		}

		void showLastResult() {
			display.showLastResult(lastResult);
		}
};

