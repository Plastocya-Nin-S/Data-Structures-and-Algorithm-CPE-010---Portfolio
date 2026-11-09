#ifndef BALANCEDSYMBOLS_H
#define BALANCEDSYMBOLS_H

#include <iostream>
#include <string>
using namespace std;

// Node for linked list stack
struct Node {
    char data;
    Node* next;
};

// Global top pointer
Node* topNode = nullptr;

// Push operation
void push(char c) {
    Node* newNode = new Node();
    newNode->data = c;
    newNode->next = topNode;
    topNode = newNode;
}

// Pop operation
char pop() {
    if (topNode == nullptr) {
        return '\0'; // empty stack
    }
    char val = topNode->data;
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    return val;
}

// Check if stack is empty
bool isEmpty() {
    return topNode == nullptr;
}

// Clear stack (for next run)
void clearStack() {
    while (!isEmpty()) {
        pop();
    }
}

// Function to check balanced symbols with detailed error reporting
bool checkBalanced(const std::string& expr) {
    clearStack(); // reset before checking
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty()) {
                std::cout << "Error: Extra closing symbol '" << c << "' found." << std::endl;
                return false;
            }
            char top = pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                std::cout << "Error: Expected matching for '" << top 
                          << "' but found '" << c << "'." << std::endl;
                return false;
            }
        }
    }
    if (!isEmpty()) {
        std::cout << "Error: Missing closing symbol(s) for: ";
        while (!isEmpty()) {
            char leftover = pop();
            std::cout << "'" << leftover << "' ";
        }
        std::cout << std::endl;
        return false;
    }
    return true;
}

#endif





