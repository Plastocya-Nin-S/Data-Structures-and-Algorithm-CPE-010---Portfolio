
#include <iostream>
#include <chrono>
#include <iomanip>
#include "search_algorithms.h"

int main() {
    const int size = 100000;
    int arr[size];

    double timeTaken;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    // Create a sorted array
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Linear Search vs. Binary Search\n";
    std::cout << "Input Size: " << size << "\n\n";

    // LINEAR SEARCH - BEST CASE
    int target = arr[0];

    start = std::chrono::high_resolution_clock::now();
    int result = linearSearch(arr, size, target);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Linear Search Best Case: "
              << timeTaken << " ms\n";

    // LINEAR SEARCH - WORST CASE
    target = arr[size - 1];

    start = std::chrono::high_resolution_clock::now();
    result = linearSearch(arr, size, target);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Linear Search Worst Case: "
              << timeTaken << " ms\n";

    // BINARY SEARCH - BEST CASE
    target = arr[size / 2];

    start = std::chrono::high_resolution_clock::now();
    result = binarySearch(arr, size, target);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Binary Search Best Case: "
              << timeTaken << " ms\n";

    // BINARY SEARCH - WORST CASE
    target = arr[size - 1];

    start = std::chrono::high_resolution_clock::now();
    result = binarySearch(arr, size, target);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Binary Search Worst Case: "
              << timeTaken << " ms\n";

    return 0;
}

