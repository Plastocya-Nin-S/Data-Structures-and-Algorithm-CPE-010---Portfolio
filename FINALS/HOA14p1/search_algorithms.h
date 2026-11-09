
#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

// Linear Search
template <typename T>
int linearSearch(T arr[], int size, T target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

// Binary Search
// The array must be sorted.
template <typename T>
int binarySearch(T arr[], int size, T target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

#endif
