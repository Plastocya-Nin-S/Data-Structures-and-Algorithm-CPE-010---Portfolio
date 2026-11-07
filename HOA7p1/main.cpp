#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"

const int max_size = 100;

int main (){
    int testArray[max_size];

    srand(time(0)); //Seed the random number generator

    //Fills array with 100 random numbers
    for (int i = 0; i < max_size; i++) {    
        testArray[i] = std::rand() % 100 + 1; //std::rand = random number gen
    }

    //DISPLAYING THE ARRAY
    std::cout<<"Array elements:\n";
    displayArray(testArray, max_size);

    //BUBBLE SORT
    std::cout<<"\n\nSorting the array using Bubble Sort...\n";
    bubbleSort(testArray, max_size);
    displayArray(testArray, max_size);

    //SELECTION SORT
    std::cout<<"\n\nSorting the array using Selection Sort...\n";
    selectionSort(testArray, max_size);
    displayArray(testArray, max_size);

    //INSERTION SORT
    std::cout<<"\n\nSorting the array using Insertion Sort...\n";
    insertionSort(testArray, max_size);
    displayArray(testArray, max_size);

    return 0;
}