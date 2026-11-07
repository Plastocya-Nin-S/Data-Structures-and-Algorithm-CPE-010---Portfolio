#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1; 
int newData, elements, choice;

// Prototyping
bool isEmpty();
bool isFull();
void push();
void pop();
void Top();
// Displays all
void displayAll();

int main(){

    std::cout << "==================================================================" << std::endl;

    std::cout << "Enter the Number of Maximum elements for the New Stack (max:100): " << std::endl;
    std::cin >> elements;

    

    while(true){
        std::cout << "==================================================================" << std::endl; // for organization purposes 
        std::cout << "Stack Operations: " << std::endl;
        std::cout << "1. PUSH \n2. POP \n3. Top \n4. isEmpty \n5. isFull \n6. Display All Elements" << std::endl;
        std::cout << "Enter Choice: " << std::endl;
        std::cin >> choice;
        std::cout << "==================================================================" << std::endl; // for organization purposes

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << isEmpty() << std::endl;
            break;
            case 5: std::cout << isFull() << std::endl;
            break;
            case 6: displayAll();
            break;
            default: std::cout << "Invalid Choice" << std::endl;
            break;
            
        }
    }

    return 0; 
}

bool isEmpty(){
    // top is -1
    if(top == -1){
        std::cout << "Stack Underflow" << std::endl;
        return true;
    } 
    return false;
}

bool isFull(){
    // not equal to the maxCap
    if(top >= elements -1){
        std::cout << "Stack Overflow" << std::endl;
        return true;
    }
    return false;
}

void push(){

    // Check if the Stack is Full, if yes return an error
    if(isFull()) return;
    // Ask the User for a value to be pushed into the stack
    std::cout << "What number you want to add to the stack? " << std::endl;
    std::cin >> newData;
    // Store inside the Stack
    stack[++top]= newData;
}

void pop(){
    // Check if there are no Elements inside the stack
    if(isEmpty()) return;
    // Display the Element to be popped 
    std::cout << "The Element to be Popped: " << stack[top] << std::endl; 
    // Decrement the top
    stack[top--] = newData;
}

void Top(){
    // Check if the stack is empty
    if(isEmpty()) return;
    // Display the Top Element for Checking
    std::cout << "The Top Element: " << stack[top] << std::endl;
}

void displayAll() {
    // Check if the stack is empty
    if(isEmpty()) return;
    // Loops backwards from top down to its last element
    for (int i = top; i >= 0; i--) {
        std::cout << stack[i] << " ";
    }
    std::cout << "\n";
}

