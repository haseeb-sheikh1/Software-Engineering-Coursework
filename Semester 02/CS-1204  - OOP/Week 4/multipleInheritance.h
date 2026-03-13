#include <iostream>
#include <string>
using namespace std;

// Base Class 1: Printer
// Represents printing functionality with page count validation
class Printer {
private:
    int pagesToPrint;  // Stores the number of pages to be printed

public:
    // Setter for pagesToPrint with input validation
    void setPagesToPrint() {
        while (true) {
            cout << "Enter number of pages to print: ";
            cin >> pagesToPrint;

            // Validates that input is a positive integer
            if (cin.fail() || pagesToPrint <= 0) {
                cin.clear();              // Clears error state
                cin.ignore(1000, '\n');   // Discards invalid input
                cout << "Invalid input. Please enter a positive number.\n";
            } else {
                cin.ignore();  // Clears newline character from buffer
                break;         // Valid input received
            }
        }
    }

    // Displays printing operation with page count
    void printDocument() const {
        cout << "Printing " << pagesToPrint << " page(s)..." << endl;
    }
};

// Base Class 2: Scanner
// Represents scanning functionality with page count validation
class Scanner {
private:
    int pagesToScan;  // Stores the number of pages to be scanned

public:
    // Setter for pagesToScan with input validation
    void setPagesToScan() {
        while (true) {
            cout << "Enter number of pages to scan: ";
            cin >> pagesToScan;

            // Validates that input is a positive integer
            if (cin.fail() || pagesToScan <= 0) {
                cin.clear();              // Clears error state
                cin.ignore(1000, '\n');   // Discards invalid input
                cout << "Invalid input. Please enter a positive number.\n";
            } else {
                cin.ignore();  // Clears newline character from buffer
                break;         // Valid input received
            }
        }
    }

    // Displays scanning operation with page count
    void scanDocument() const {
        cout << "Scanning " << pagesToScan << " page(s)..." << endl;
    }
};

// Derived Class: Photocopier
// Inherits from both Printer and Scanner to combine functionalities
class Photocopier : public Printer, public Scanner {
private:
    string deviceName;  // Stores the name of the photocopier device

public:
    // Setter for device name with input validation
    void setDeviceName() {
        while (true) {
            cout << "Enter device name: ";
            getline(cin, deviceName);  // Reads full device name including spaces

            if (!deviceName.empty()) break;  // Valid input
            cout << "Device name cannot be empty. Try again.\n";
        }
    }

    // Displays completion message for photocopy operation
    void startPhotocopy() {
        cout << "Photocopy completed.\n";
    }
};
