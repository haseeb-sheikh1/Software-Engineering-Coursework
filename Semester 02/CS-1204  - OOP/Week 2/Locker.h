#include<iostream> // including input/output stream library
#include<string> // including string library
using namespace std;

class Locker{
	public : // access specifier
	// default constructor
	Locker(){ 
		cout << "Locker allocated to customer." << endl;	
	}
	
	// default destructor
	~Locker(){
		cout << "Locker returned by customer." << endl;
	}
};