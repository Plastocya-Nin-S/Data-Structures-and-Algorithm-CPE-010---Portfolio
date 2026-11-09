
#include <iostream>
#include <chrono>
#include <iomanip>
#include "sort_algorithms.h"

// Generate a best-case arrangement for Quick Sort
// when the last element is used as the pivot.
void buildBestCase(int low, int high, int arr[], int& index) {
    if (low > high)
        return;

    int mid = low + (high - low) / 2;

    buildBestCase(low, mid - 1, arr, index);
    buildBestCase(mid + 1, high, arr, index);

    arr[index++] = mid + 1;
}

int main() {
    const int size = 1000;
    int arr[size];

    double timeTaken;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Selection Sort vs. Quick Sort\n";
    std::cout << "Input Size: " << size << "\n\n";

    // SELECTION SORT - BEST CASE
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;

    start = std::chrono::high_resolution_clock::now();
    selectionSort(arr, size);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Selection Sort Best Case: "
              << timeTaken << " ms\n";

    // SELECTION SORT - WORST CASE
    for (int i = 0; i < size; i++)
        arr[i] = size - i;

    start = std::chrono::high_resolution_clock::now();
    selectionSort(arr, size);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Selection Sort Worst Case: "
              << timeTaken << " ms\n";

    // QUICK SORT - BEST CASE
    int bestArr[size];
    int index = 0;

    buildBestCase(0, size - 1, bestArr, index);

    start = std::chrono::high_resolution_clock::now();
    quickSort(bestArr, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Quick Sort Best Case: "
              << timeTaken << " ms\n";

    // QUICK SORT - WORST CASE
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;

    start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();

    timeTaken = std::chrono::duration<double, std::micro>(
        end - start).count();

    std::cout << "Quick Sort Worst Case: "
              << timeTaken << " ms\n";

    return 0;
}


