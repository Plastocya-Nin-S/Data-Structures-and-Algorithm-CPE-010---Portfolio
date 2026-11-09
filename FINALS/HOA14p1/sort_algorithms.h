#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <algorithm>

// Selection Sort helper: returns the position of the smallest element
// from index k through maxSize - 1.
template <typename T>
int routine_smallest(T arr[], int k, const int maxSize) {
    int position = k;
    T smallestElement = arr[k];

    for (int j = k + 1; j < maxSize; j++) {
        if (arr[j] < smallestElement) {
            smallestElement = arr[j];
            position = j;
        }
    }

    return position;
}

template <typename T>
void selectionSort(T arr[], int maxSize) {
    for (int i = 0; i < maxSize - 1; i++) {
        int minVal = routine_smallest(arr, i, maxSize);
        std::swap(arr[i], arr[minVal]);
    }
}

// Quick Sort partition function (Lomuto partition scheme).
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;

            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    T temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif
