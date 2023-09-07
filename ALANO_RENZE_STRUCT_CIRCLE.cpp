#include <iostream>
#include <iomanip> // used to manipulate the output stream format of floating point numbers to a fixed decimal precision of 2

using namespace std;

// Define a struct to represent a circle
struct Circle {
    float rad;
};

// Function to calculate the circumference of a circle given its radius
float calculateCircumference(Circle circle) {
    return 2 * 3.14159 * circle.rad;
}

// Function to calculate the area of a circle given its radius
float calculateArea(Circle circle) {
    return 3.14159 * circle.rad * circle.rad;
}

int main() {
    Circle circle1;
    cout << "Enter radius: ";
    cin >> circle1.rad;

    // Calculate the circumference and area of the circle
    float circumference = calculateCircumference(circle1);
    float area = calculateArea(circle1);

    // Set output to fixed decimal precision of 2
    cout << fixed << setprecision(2); 
    cout << "Circumference: " << circumference << endl;
    cout << "Area: " << area << endl;

    return 0;
}
