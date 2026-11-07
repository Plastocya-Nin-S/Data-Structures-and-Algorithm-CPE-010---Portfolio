#include <iostream>
#include <cmath> // for sqrt and pow

class Triangle {
private:
    double sideA, sideB, sideC; // sides of the triangle

public:
    // Constructor
    Triangle(double a, double b, double c);

    void setSides(double a, double b, double c);

    const bool validateTriangle();

    double computeArea();       // Function to compute area
    double computePerimeter();  // Function to compute perimeter
    std::string classifyTriangle(); // Function to classify triangle
};

int main() {
    double a, b, c;

    // User input
    std::cout << "Enter side A: ";
    std::cin >> a;
    std::cout << "Enter side B: ";
    std::cin >> b;
    std::cout << "Enter side C: ";
    std::cin >> c;

    // Creates Triangle object with user-defined sides
    Triangle userTriangle(a, b, c);

    if (userTriangle.validateTriangle()) {
        std::cout << "\nThe shape is a valid triangle.\n";
        std::cout << "Perimeter: " << userTriangle.computePerimeter() << std::endl;
        std::cout << "Area: " << userTriangle.computeArea() << std::endl;
        std::cout << "Classification: " << userTriangle.classifyTriangle() << std::endl;
    } else {
        std::cout << "\nThe shape is NOT a valid triangle.\n";
    }

    return 0;
}

// Methods definition

Triangle::Triangle(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

void Triangle::setSides(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

const bool Triangle::validateTriangle() {
    // Triangle inequality theorem
    return (sideA + sideB > sideC &&
            sideA + sideC > sideB &&
            sideB + sideC > sideA);
}

double Triangle::computePerimeter() {
    return sideA + sideB + sideC;
}

double Triangle::computeArea() {
    double s = computePerimeter() / 2.0; // semi-perimeter
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

std::string Triangle::classifyTriangle() {
    // Sort sides so that c is the largest
    double a = sideA, b = sideB, c = sideC;
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);

    double lhs = a*a + b*b;
    double rhs = c*c;

    if (std::fabs(lhs - rhs) < 1e-9) {
        return "Right-angled";
    } else if (lhs > rhs) {
        return "Acute-angled";
    } else if (lhs < rhs) {
        return "Obtuse-angled";
    } else {
        return "Others";
    }
}

