#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>

// node used for the linked list
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

// Problem 1 - Sequential Search using Array
template <typename T>
int sequentialSearchArray(T arr[], int size, T key) {
    int comparisons = 0;

    // check each element starting from the first one
    for (int i = 0; i < size; i++) {
        comparisons++;
        // stop once the key is found
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

// Problem 1 - Sequential Search using Linked List
template <typename T>
int sequentialSearchLinkedList(Node<T>* head, T key) {
    int comparisons = 0;
    // go through the nodes one at a time
    while (head != nullptr) {
        comparisons++;
        // check if the current node contains the key
        if (head->data == key) {
            return comparisons;
        }
        // move to the next node
        head = head->next;
    }
    return comparisons;
}

// Problem 2 - Count Repeating Instances
template <typename T>
int countOccurrences(T arr[], int size, T key) {
    int count = 0;
    // check the whole list so every occurrence is counted
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

// Problem 3 - Iterative Binary Search
template <typename T>
int binarySearch(T arr[], int size, T key) {
    int low = 0;
    int high = size - 1;
    int iteration = 1;
    // continue searching while the range is valid
    while (low <= high) {
        // find the middle position
        int mid = (low + high) / 2;
        std::cout << "Iteration " << iteration
                  << ": Low = " << low
                  << ", High = " << high
                  << ", Mid = " << mid
                  << ", Value = " << arr[mid]
                  << std::endl;

        // check if the middle value is the key
        if (arr[mid] == key) {
            return mid;
        }
        // move to the left half if the key is smaller
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        // otherwise move to the right half
        else {
            low = mid + 1;
        }
        iteration++;
    }

    return -1;
}

// Problem 4 - Recursive Binary Search
template <typename T>
int recursiveBinarySearch(T arr[], int low, int high, T key, int& iteration) {
    // stop when there is no range left to search
    if (low > high) {
        return -1;
    }
    // find the middle position of the current range
    int mid = (low + high) / 2;
    std::cout << "Iteration " << iteration
              << ": Low = " << low
              << ", High = " << high
              << ", Mid = " << mid
              << ", Value = " << arr[mid]
              << std::endl;
    // return the position when the key is found
    if (arr[mid] == key) {
        return mid;
    }
    iteration++;
    // search the left half if the key is smaller
    if (key < arr[mid]) {

        return recursiveBinarySearch(arr, low, mid - 1, key, iteration);
    }

    // otherwise search the right half
    return recursiveBinarySearch(arr, mid + 1, high, key, iteration);
}

#endif