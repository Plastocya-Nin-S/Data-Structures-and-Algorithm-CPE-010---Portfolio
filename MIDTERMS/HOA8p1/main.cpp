#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";

        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}


int main() {
    srand(time(0));
    const int SIZE = 100;

    int original[SIZE];
    int shellArray[SIZE];
    int mergeArray[SIZE];
    int quickArray[SIZE];

    // Generates 100 random values for the array
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1000 + 1;
    }

    // Copies the same array for each sorting algorithm to sort the same values
    for (int i = 0; i < SIZE; i++) {
        shellArray[i] = original[i];
        mergeArray[i] = original[i];
        quickArray[i] = original[i];
    }

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "ARRAY OF VALUES FOR SORT ALGORITHM TESTING" << std::endl;
    std::cout << "Original 100 Random Values:" << std::endl;
    displayArray(original, SIZE);

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "SHELL SORT TECHNIQUE" << std::endl;
    shellSort(shellArray, SIZE);
    std::cout << "Sorted Array using Shell Sort:" << std::endl;
    displayArray(shellArray, SIZE);

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "MERGE SORT ALGORITHM" << std::endl;
    mergeSort(mergeArray, 0, SIZE - 1);
    std::cout << "Sorted Array using Merge Sort:" << std::endl;
    displayArray(mergeArray, SIZE);

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "QUICK SORT ALGORITHM" << std::endl;
    quickSort(quickArray, 0, SIZE - 1);
    std::cout << "Sorted Array using Quick Sort:" << std::endl;
    displayArray(quickArray, SIZE);
    std::cout << "--------------------------------------------" << std::endl;

    return 0;
}