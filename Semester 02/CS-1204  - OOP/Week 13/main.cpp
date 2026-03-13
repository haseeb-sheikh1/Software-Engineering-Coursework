//                                                                      LAB # 13- TEMPLATES
//                                                                      DATED: 8-9-2025
//                                           TASK NUMBER 1 : CALCULATOR USING TEMPLATES AND EXCEPTION HANDLING
#include <iostream>
#include <stdexcept>
using namespace std;

// Function templates
template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T subtract(T a, T b) { return a - b; }

template <typename T>
T multiply(T a, T b) { return a * b; }

template <typename T>
T divide(T a, T b) {
    if (b == 0) throw runtime_error("Error: Division by zero is not allowed.");
    return a / b;
}

int main() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    try {
        double result;

        switch (op) {
            case '+': result = add(num1, num2); break;
            case '-': result = subtract(num1, num2); break;
            case '*': result = multiply(num1, num2); break;
            case '/': result = divide(num1, num2); break;
            default: throw invalid_argument("Error: Invalid operation entered.");
        }

        cout << "Result: " << result << endl;

    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

//                                           TASK NUMBER 1 : LOGGER CLASS USING TEMPLATES

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Template Logger class
template <typename T>
class Logger {
private:
    string logPrefix;
    ofstream logFile;

public:
    // Constructor: optionally specify a prefix and file name
    Logger(const string& prefix = "LOG", const string& filename = "log.txt")
        : logPrefix(prefix), logFile(filename, ios::app) {
        if (!logFile.is_open()) {
            throw runtime_error("Failed to open log file.");
        }
    }

    // Log a message of type T
    void log(const T& message) {
        logFile << "[" << logPrefix << "] " << message << endl;
        cout << "[" << logPrefix << "] " << message << endl;
    }

    // Change the prefix dynamically
    void setPrefix(const string& prefix) {
        logPrefix = prefix;
    }

    // Destructor: close the file
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};