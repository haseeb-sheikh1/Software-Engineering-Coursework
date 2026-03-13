#include <iostream>
using namespace std;

class Rectangle {
private: // access specifier
    float length;
    float width;

public: // access specifier
    // Default constructor 
    Rectangle() {
        length = 1.0f;
        width = 1.0f;
    }

    // Parameterized constructor 
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    // Single-parameter constructor (creating a square)
    Rectangle(float side) {
        length = side;
        width = side;
    }

    // Method to calculate the area
    float area() const {
        return length * width;
    }

    // Method to display rectangle details
    void display() const {
        cout << "Length: " << length << ", Width: " << width << ", Area: " << area() << endl;
    }
};



