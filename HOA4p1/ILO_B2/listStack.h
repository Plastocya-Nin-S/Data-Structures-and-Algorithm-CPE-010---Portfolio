#ifndef LISTSTACK_H
#define LISTSTACK_H
#include<iostream>

// Class node with data and next members (public)
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next = nullptr;
};

// Create a Pointer/Reference tip that 
// always points to the current top node
// Global
template <typename T>
Node<T>* head = nullptr;


// Pushing Operations:
template <typename T>
void push(T newData){
    // Create a newNode
    Node<T>* newNode = new Node<T>;
    // Assign the data to the newNode
    newNode->data = newData;
    // Point the newNode next to the current Top
    newNode->next = head<T>;
    // Assign the new Top to the newNode
    head<T> = newNode;
}

// IsEmpty for Checking:
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

// Popping Operations:
template <typename T>
T pop(){
    // If the stack is empty error catch:
    if(isEmpty<T>()){
        std::cout << "Stack Underflow" << std::endl;
    }
    // Saving a Current Top Node
    Node<T>* tempNode = head<T>;
    // Store the data of the top node to a temporary variable
    T tempVal = tempNode->data;
    // Move the head to the next node
    head<T> = head<T>->next;
    // Free up the memory
    delete tempNode;
    // Return the temporary variable data 
    return tempVal;
}

// Top Checking Operations:
template <typename T>
void Top(){
    // What if ???? the stack is Empty
    if(isEmpty<T>()) return;

    std::cout << "The Top is: " << head<T>->data << std::endl;


}

template <typename T>
void displayAll(){
    // Checks if the Stack/Linked List is empty
    if (head<T> == nullptr){
        std::cout << "List is Empty" << std::endl;
        return;
    }
    const Node<T>* currNode = head<T>;
    // Prints data until reaches null
    while(currNode != nullptr){
        std::cout << currNode->data; 
        // creates an arrow everytime it confirms that data is != to null
        if (currNode->next != nullptr){
            std::cout << "->";
        }
        // Considers every next data as the head
        currNode = currNode->next;
    }
    std::cout << std::endl;
}












#endif