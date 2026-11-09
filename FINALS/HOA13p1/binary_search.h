
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex resultMutex;
int foundIndex = -1;

// Binary search function
void binarySearch(const std::vector<int>& arr,
                  int left, int right,
                  int target,
                  const char* threadName) {
    int low = left;
    int high = right;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    {
        std::lock_guard<std::mutex> lock(resultMutex);

        if (result != -1 && foundIndex == -1) {
            foundIndex = result;
        }

        if (result != -1) {
            std::cout << threadName
                      << " found the target at index "
                      << result << ".\n";
        }
        else {
            std::cout << threadName
                      << " did not find the target in its section.\n";
        }
    }
}

#endif
