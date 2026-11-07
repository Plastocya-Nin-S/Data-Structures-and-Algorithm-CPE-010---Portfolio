#include<iostream>
#include "listStack.h"

int main(){
    std::cout << "---------- Pushing 'I' 'E' 'E' 'E' ---------- \n";

    // Pushing
    push('I');
    push('E');
    push('E');
    push('E');

    // Display Top
    Top<char>();
    std::cout << "-------------------------------------------- \n";

    // Display All Elements in the List
    std::cout << "Display of All the ELements: ";
    displayAll<char>();

    // Pop And Print Each Element
    std::cout << "---------- Popping 'I' 'E' 'E' 'E' ---------- \n";
    while(!isEmpty<char>()){
        std::cout << "Popping: " << pop<char>() << std::endl; 
    }

    // Test Stack Underflow
    std::cout << "-------------------------------------------- \n";
    pop<char>();

}

