#include <iostream>
#include <cmath> // for sqrt and pow

// Function declaration
double calculateDistance(double x1, double y1, double x2, double y2);

int main() {
    double x1, y1, x2, y2;

    // Asks for User Input of Point Coordinates
    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter y1: ";
    std::cin >> y1;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout << "Enter y2: ";
    std::cin >> y2;

    // Calls function to calculate the Distance
    double distance = calculateDistance(x1, y1, x2, y2);

    // Displays the calculated result
    std::cout << "The distance between (" << x1 << ", " << y1 << ") and ("
              << x2 << ", " << y2 << ") is: " << distance << std::endl;

    return 0;
}

// Function definition
double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}



