#include <iostream>
#include <cstdlib> // for generating random integers
#include <time.h> // will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50; 

int main(){

    // Generate a random number between 1 and 50
    int dataset[max_size];
    srand(time(0)); //seed the random number generator
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand(); //random number between 1 and 50
    }
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int userInput;
    std::cout << "What number to search?";
    std::cin >> userInput;
    std::cout << "============================================" << std::endl;
    std::cout << "Array result LS: ";
    linearSearchArr(dataset, max_size, userInput); //search for the entered number in the dataset
    std::cout << "Array result BS: ";
    binarySearchArr(dataset, max_size, userInput); //search for the entered number in the dataset
    std::cout << "--------------------------------------------" << std::endl;

    // Create a linked list
    Node<char>* name1 = newNode('J');
    Node<char>* name2 = newNode('I');
    Node<char>* name3 = newNode('M');
    Node<char>* name4 = newNode('L');
    Node<char>* name5 = newNode('O');
    Node<char>* name6 = newNode('R');
    Node<char>* name7 = newNode('D');

    // Create the Name
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;

    // Demonstration
    std::cout << "============================================" << std::endl;
    std::cout << "Linked List result LS: ";
    linearSearchLL(name1, 'R');
    linearSearchLL(name1, 'r');
    std::cout << "Linked List result BS: ";
    binarySearchLL(name1, 'R');
    binarySearchLL(name1, 'r');
    std::cout << "--------------------------------------------" << std::endl;

    // Testing for GetMiddle
    Node<int>* he_ad = newNode(10);
    he_ad->next = newNode(20);
    he_ad->next->next = newNode(30);
    he_ad->next->next->next = newNode(40);
    he_ad->next->next->next->next = newNode(50);

    Node<int>* mid = getMiddle<int>(he_ad, nullptr);
    if (mid != nullptr)
        std::cout << "Middle node value: " << mid->data << std::endl;

    // create a linked list for binary search
    // make sure the values are ordered
    char choice = 'y';
    int count = 1;
    int newData;
    Node<int> *temp, *head, *node;

    while (true) {
        std::cout << "Enter data: ";
        std::cin >> newData;

        if (count == 1) {
            head = newNode(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } else if (count == 2) {
            node = newNode(newData);
            head->next = node;
            node->next = NULL;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        } else {
            temp = head;
            while (true) {
                if (temp->next == NULL) break;
                temp = temp->next;
            }
            node = newNode(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }

        // when to end
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') break;
    }

    // optional snippet to verify data stored in linked list
    std::cout << "\nLinked list contents: ";
    Node<int>* currNode = head;
    while (currNode != NULL) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;

}






