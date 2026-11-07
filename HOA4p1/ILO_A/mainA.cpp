#include <iostream>
#include <stack> // call the stack from the STL
#include <string>

struct Item {
    std::string name;
    int quantity;

    // Constructor
    Item(std::string n, int q) : name(n), quantity(q) {
        std::cout << "Item constructed: " << name << "\n";
    }
};


int main(){

        std::stack<int> newStack; // Created an Object
        std::stack<int> nextStack; // Created an Object
        std::stack<Item> inventory; // Created an Object

        // Testing the empty() function to check if the stack is empty
        std::cout << "Is the Stack Empty?? " << newStack.empty() << std::endl;

std::cout << "=======================================" << std::endl;

        // Insert 3 elements and Checks & Returns the Top
        newStack.push(3);
        std::cout << "Top of the Stack: " << newStack.top() << std::endl;
        newStack.push(2);
        std::cout << "Top of the Stack: " << newStack.top() << std::endl;
        newStack.push(1);
        std::cout << "Top of the Stack: " << newStack.top() << std::endl;

std::cout << "=======================================" << std::endl;

        std::cout << "Is the Stack Empty?? " << newStack.empty() << std::endl;

std::cout << "=======================================" << std::endl;

        // Inserts more elements 
        nextStack.push(6);
        nextStack.push(7);
        nextStack.push(8);

        // Checks the size of the stack 
        std::cout << "Size of the Stack is: " << newStack.size() << std::endl;

std::cout << "=======================================" << std::endl;

        // Swap -> Swaps the contents of the public member functions
        newStack.swap(nextStack);
        // Checks if the swap works
        std::cout << "New Stack's TOP is now: " << newStack.top() << std::endl;

std::cout << "=======================================" << std::endl;

        // Emplace -> Constructs and Insert Elements of public member function
        inventory.emplace("Makeup", 7);
        // Checks the top object
        std::cout << "Top item in the stack rn: " << inventory.top().name << std::endl;

std::cout << "=======================================" << std::endl;

    return 0;
}

