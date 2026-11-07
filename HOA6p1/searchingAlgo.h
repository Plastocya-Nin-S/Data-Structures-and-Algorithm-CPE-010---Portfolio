#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include <algorithm> // allows sortings

template <typename T>
void linearSearchArr (T list[], int arrSize, T dataFind){
    // Initialize i = 0
    int i = 0;
    // While i <= n
    while (i < arrSize) {
        //if (item = data[i])
        if (list[i] == dataFind) {
            // Print Searching is Successful
            std::cout << "Searching is Successful" << std::endl;
            std::cout << "Element found at index " << i << std::endl;
            return;
        }
        i++;
    }
    // Print Searching is Unsuccessful
    std::cout << "Searching is Unsuccessful" << std::endl;
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind){

    int i = 0;
    // While i != nullptr
    while(head != nullptr){
        //  
        if(head->data == dataFind){
            std::cout << "\nSearching is Successful" << std::endl;
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is Unsuccessful" << std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    if (start == nullptr) return nullptr;

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){

        // move slow one step
        slow = slow->next;

        // move fast two steps
        fast = fast->next->next;
    }

    return slow;
}

// Linked List implementation Binary Search
template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    // Step 1: Initialize last = nullptr
    Node<T>* last = nullptr;

    // Step 2: Repeat while start != last
    while (start != last) {
        // mid = getMiddle(start, last)
        Node<T>* mid = getMiddle(start, last);

        if (mid == nullptr) {
            std::cout << "\nSearching is Unsuccessful" << std::endl;
            return;
        }
        // if (dataFind == mid->data)
        if (mid->data == dataFind) {
            std::cout << "\nSearching is Successful" << std::endl;
            return;
        }
        // else if (dataFind < mid->data) then last = mid
        else if (dataFind < mid->data) {
            last = mid;
        }
        // else start = mid->next
        else {
            start = mid->next;
        }
    }

    // Step 3: Print Searching is Unsuccessful
    std::cout << "Searching is Unsuccessful" << std::endl;
}


// Array implementation Binary Search
template <typename T>
void binarySearchArr(T list[], int arrSize, T dataFind) {
    // IMPORTANT: Sort array before binary search
    std::sort(list, list + arrSize);

    // Step 1: low = 0, up = n-1
    int low = 0;
    int up = arrSize - 1;
    int middle;

    // Step 2: Repeat while low <= up
    while (low <= up) {
        // mid = (low + up) / 2
        middle = (int)(low + up) / 2;

        // if (dataFind == list[mid])
        if (list[middle] == dataFind) {
            std::cout << "Searching is Successful" << std::endl;
            std::cout << "Element found at index " << middle << std::endl;
            return;
        }
        // else if (dataFind < list[middle]) then up = middle - 1
        else if (dataFind < list[middle]) {
            up = middle - 1;
        }
        // else low = middle + 1
        else {
            low = middle + 1;
        }
    }

    // Step 3: Print Searching is Unsuccessful
    std::cout << "Searching is Unsuccessful" << std::endl;
}






#endif