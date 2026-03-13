//                                                              LAB # 12- EXCEPTION HANDLING
//                                                                   DATED: 31-8-2025
//                                                       TASK NUMBER 1: HANDLE DIVIDING BY ZERO

#include <iostream>
#include <stdexcept> // For runtime_error or exception
using namespace std;
// Function to perform division
double safe_divide(int numerator, int denominator) {
    if (denominator == 0) {
        // Throw a specific exception when division by zero occurs
        throw runtime_error("Error: Cannot divide by zero.");
    }
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int a, b;
    cout << "Enter numerator (a): ";
    cin >> a;
    cout << "Enter denominator (b): ";
    cin >> b;

    try {
        double result = safe_divide(a, b);
        cout << "Result of " << a << " / " << b << " is: " << result << endl;
    }
    // Catch the specific exception type
    catch (const runtime_error& e) {
        // Output the error message from the exception
        cerr << "Exception caught: " << e.what() << endl;
    }
    // Optional: catch any other standard exceptions
    catch (const exception& e) {
        cerr << "A general exception occurred: " << e.what() << endl;
    }
    // Optional: catch any unknown exceptions
    catch (...) {
        cerr << "An unknown error occurred." << endl;
    }

    return 0;
}


//                                                        TASK NUMBER 2: ARRAY INDEX OUT OF BOUND

#include <iostream>
#include <stdexcept> // For out_of_range

using namespace std;

void modify_array() {
    // Initialize a fixed-size array of size 3
    int arr[3] = {0, 0, 0};
    int index;
    int value;

    cout << "The array size is 3 (valid indices are 0, 1, 2)." << endl;
    cout << "Enter the index (0-2) you want to modify: ";
    cin >> index;
    cout << "Enter the value to store: ";
    cin >> value;

    // Check for out-of-bounds index
    if (index < 0 || index >= 3) {
        string msg = "Error: Index " + to_string(index) + " is out of bounds [0, 2]";
        throw out_of_range(msg);
    }

    // Valid index: store the value
    arr[index] = value;
    cout << "Successfully stored " << value << " at index " << index << "." << endl;
}

int main() {
    try {
        modify_array();
    }
    catch (const out_of_range& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }
    catch (...) {
        cerr << "An unexpected error occurred during array modification." << endl;
    }

    return 0;
}



