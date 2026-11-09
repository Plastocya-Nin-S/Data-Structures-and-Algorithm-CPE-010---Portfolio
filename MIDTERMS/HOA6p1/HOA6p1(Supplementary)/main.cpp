#include <iostream>
#include <iomanip>
#include "searchingAlgo.h"

int main() {

    // Problem 1 - Sequential Search
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int key = 18;

    std::cout << "\n=======================================================\n";
    std::cout << "       PROBLEM 1 - SEQUENTIAL SEARCH\n";
    std::cout << "=======================================================\n";

    std::cout << "List: ";
    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }

    std::cout << "\nSearch Key: " << key << "\n\n";

    // Search using array
    int arrayComparisons =
        sequentialSearchArray(list, size, key);

    // Create linked list
    Node<int>* head = new Node<int>(list[0]);
    Node<int>* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node<int>(list[i]);
        current = current->next;
    }

    // Search using linked list
    int linkedListComparisons =
        sequentialSearchLinkedList(head, key);

    std::cout << "Results:\n";
    std::cout << "Array Comparisons      : "
              << arrayComparisons << "\n";

    std::cout << "Linked List Comparisons: "
              << linkedListComparisons << "\n";


    // Problem 2 - Count Repeating Instances
    std::cout << "\n=======================================================\n";
    std::cout << "    PROBLEM 2 - COUNT REPEATING INSTANCES\n";
    std::cout << "=======================================================\n";

    std::cout << "List: ";
    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }

    std::cout << "\nSearch Element: " << key << "\n";

    int occurrences =
        countOccurrences(list, size, key);

    std::cout << "\nResults:\n";
    std::cout << "Number of occurrences: "
              << occurrences << "\n";


    // Problem 3 - Iterative Binary Search
    std::cout << "\n=======================================================\n";
    std::cout << "    PROBLEM 3 - ITERATIVE BINARY SEARCH\n";
    std::cout << "=======================================================\n";

    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int sortedSize = 10;
    int binaryKey = 8;

    std::cout << "Sorted List: ";
    for (int i = 0; i < sortedSize; i++) {
        std::cout << sortedList[i] << " ";
    }

    std::cout << "\nSearch Element: "
              << binaryKey << "\n\n";

    std::cout << "Search Process:\n";

    int result =
        binarySearch(sortedList, sortedSize, binaryKey);

    std::cout << "\nResults:\n";

    if (result != -1) {
        std::cout << "Search Status: Successful\n";
        std::cout << "Element found at index: "
                  << result << "\n";
    }
    else {
        std::cout << "Search Status: Unsuccessful\n";
    }


    // Problem 4 - Recursive Binary Search
    std::cout << "\n=======================================================\n";
    std::cout << "    PROBLEM 4 - RECURSIVE BINARY SEARCH\n";
    std::cout << "=======================================================\n";

    std::cout << "Sorted List: ";
    for (int i = 0; i < sortedSize; i++) {
        std::cout << sortedList[i] << " ";
    }

    std::cout << "\nSearch Element: "
              << binaryKey << "\n\n";

    std::cout << "Search Process:\n";

    int iteration = 1;

    int recursiveResult =
        recursiveBinarySearch(
            sortedList,
            0,
            sortedSize - 1,
            binaryKey,
            iteration
        );

    std::cout << "\nResults:\n";

    if (recursiveResult != -1) {
        std::cout << "Search Status: Successful\n";
        std::cout << "Element found at index: "
                  << recursiveResult << "\n";
    }
    else {
        std::cout << "Search Status: Unsuccessful\n";
    }

    // Delete linked list
    Node<int>* temp = head;

    while (temp != nullptr) {
        Node<int>* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}