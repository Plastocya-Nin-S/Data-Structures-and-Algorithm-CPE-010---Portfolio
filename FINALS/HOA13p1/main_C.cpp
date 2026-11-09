
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <functional>
#include "binary_search.h"

int main() {
    int size;
    int target;

    std::cout << "=== Binary Search Using Multithreading ===\n";

    // Ask the user for the vector size
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    if (std::cin.fail() || size <= 0) {
        std::cout << "Invalid size. Please enter a positive integer.\n";
        return 1;
    }

    // Generate random numbers
    std::vector<int> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < size; i++) {
        arr.push_back(dist(gen));
    }

    // Sort the vector for binary search
    std::sort(arr.begin(), arr.end());

    // Display the generated vector
    std::cout << "\nGenerated sorted vector:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Ask the user for the target
    std::cout << "\nEnter the number to search for: ";
    std::cin >> target;

    if (std::cin.fail()) {
        std::cout << "Invalid target. Please enter an integer.\n";
        return 1;
    }

    // Reset the shared result for this search
    foundIndex = -1;

    // Divide the vector into two sections
    int mid = size / 2;

    std::cout << "\nSearching using two threads...\n";

    std::thread T1(
        binarySearch,
        std::cref(arr),
        0, mid - 1,
        target,
        "Thread 1"
    );

    std::thread T2(
        binarySearch,
        std::cref(arr),
        mid, size - 1,
        target,
        "Thread 2"
    );

    // Wait for both threads
    T1.join();
    T2.join();

    // Display the final result
    if (foundIndex != -1) {
        std::cout << "\nResult: " << target
                  << " found at index "
                  << foundIndex << ".\n";
    }
    else {
        std::cout << "\nResult: " << target
                  << " was not found in the vector.\n";
    }

    return 0;
}
