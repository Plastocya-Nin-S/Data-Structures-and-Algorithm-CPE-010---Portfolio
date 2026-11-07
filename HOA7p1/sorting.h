#ifndef SORTING_H
#define SORTING_H

#include <iostream>

//DISPLAYING ALL ARRAY ELEMENTS
void displayArray(const int values[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << values[i] << ' ';

        if ((i + 1) % 10 == 0) {
            std::cout << "";
        }
    }
}

//bubble sorting
template <typename T>
void bubbleSort (T arr[], size_t maxSize) {
    for (int i = 0; i < maxSize - 1; i++) {
        for (int j = i+1; j < maxSize; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

//selection sorting
template <typename T>
int routine_smallest (T arr[], int K, const int maxSize) {
    int position, j;
    T smallestElement = arr[K]; //smallest element = first element
    position = K; //position = first element

    //if j (current) is smaller than k, set the position to j and current smallest element to j
    for (int j = K + 1; j < maxSize; j++) {
        if (arr[j] < smallestElement) {
            smallestElement = arr[j];
            position = j;
        }
    }
    // return the position of the smallest element
    return position;
}

template <typename T>
void selectionSort (T arr[], int maxSize) {
    int minVal;

    for (int i = 0; i < maxSize - 1; i++) {
        minVal = routine_smallest(arr, i, maxSize);
        std::swap(arr[i], arr[minVal]);
    }
}

//insertion sorting
template <typename T>
void insertionSort (T arr[], int maxSize) {
    int k = 1, j;
    T temp; //swapping, cannot use std::swap
    
    while (k < maxSize) {
        temp = arr[k];
        j = k - 1;

        while (j >= 0 && temp <= arr[j]){
            arr[j + 1] = arr[j];
            j--; //backtracking part
        }
        //reassigning values and moving to next element
        arr[j + 1] = temp;
        k++;
    }
}

//=======================SUPPLEMENTARY=========================
//searches for the number of votes
template <typename T>
int CountVotes (const T arr[], int maxSize, T candidate) {
    int votes = 0;

    for (int i = 0; i < maxSize; i++) {
        if (arr[i] == candidate) {
            votes++;
        }
    }

    return votes;
}
#endif
