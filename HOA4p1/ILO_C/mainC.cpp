#include "balancedStack.h"
#include <iostream>
#include <string>

int main() {
    std::string expr;
    char choice;

    do {
        std::cout << "====================================================" << std::endl;
        std::cout << "Enter an expression: ";
        std::cin >> expr;

        if (checkBalanced(expr)) {
            std::cout << "Expression is balanced!" << std::endl;
        } else {
            std::cout << "Expression is NOT balanced!" << std::endl;
        }

        std::cout << "====================================================" << std::endl;
        std::cout << "Do you want to check another expression? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Program terminated. Goodbye!" << std::endl;
    return 0;
}


