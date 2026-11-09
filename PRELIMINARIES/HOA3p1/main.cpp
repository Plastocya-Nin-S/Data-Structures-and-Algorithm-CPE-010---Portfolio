#include <iostream>
#include "double_LL.h"

int main(){

    // Creating First node 'C' 'P' 'E'
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    // Linking the nodes together
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "================================" << std::endl; // Organization

    // Traversing the list forward
    std::cout << "Traversal testing: \n" << std::endl;
    dllTraverse(head);    

    std::cout << "================================" << std::endl; // Organization
    
    // Inserting a new node at the head
    std::cout << "Inserting Head testing: \n" << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout << "================================" << std::endl; // Organization

    // Inserting a new node at the End
    std::cout << "Inserting End testing: \n" << std::endl;
    dllInsertTail('Z', head);
    dllTraverse(head);

    std::cout << "================================" << std::endl; // Organization

    // Inserting a new node at any position
    std::cout << "Inserting at any position testing: \n" << std::endl;
    dllGeneralInsert('Y', head->next, head->next->next);
    dllTraverse(head);

    std::cout << "================================" << std::endl; // Organization

    // Deletion of a Node
    std::cout << "Deleting Node testing: \n" << std::endl;
    dllDeleteNodes('Y', &head);
    dllTraverse(head);

    std::cout << "================================" << std::endl; // Organization


    return 0;
}



