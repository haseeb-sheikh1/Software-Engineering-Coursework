#include <iostream>
#include"Composition.h"
#include"Aggregation.h"
using namespace std;

//                                                             LAB NUMBER 5 - COMPOSITION AND AGGREGATION
//                                                                       DATED: 30-May-2025

int main() {

	// COMPOSITION TASK
	Calculator calc;
	calc.add(15.5, 7.2);
	calc.showLastResult();

	// AGGREGATION TASK
	// The calculator object exists independently
	Calculator sharedCalc;
	// Multiple students share the same calculator
	Student student1("Alice", &sharedCalc);
	Student student2("Bob", &sharedCalc);
	student1.performCalculation(20.0, 5.0);
	student2.performCalculation(30.0, 10.0);

	return 0;
}


