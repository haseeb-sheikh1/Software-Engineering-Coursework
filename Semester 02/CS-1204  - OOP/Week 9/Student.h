#include<iostream>
using namespace std;
class Student {
	private:
		double id;
		static double count; // static data member


	public:
		Student (double id) {
			id = id;
			count++;
		}

		static void showCount () { // static function
			cout << "Total Students: " << count;

		}
};
double Student::count =0; // defination of static member
