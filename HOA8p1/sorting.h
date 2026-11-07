#ifndef SORTING_H
#define SORTING_H

#include <vector>

// Shell Sort
template<typename T>
void shellSort(T arr[], int size){
    for (int gap = size / 2; gap > 0; gap /= 2){
        for (int i = gap; i < size; i++){
            T temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}


// Merge function for Merge Sort
template<typename T>
void merge(T arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++){
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }
    while (i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


// Merge Sort
template<typename T>
void mergeSort(T arr[], int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}


// Partition function for Quick Sort
template<typename T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
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


// Quick Sort
template<typename T>
void quickSort(T arr[], int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif