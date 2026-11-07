#include <iostream>
#include <vector>

// Global Declaration
void inputList(std::vector<int> &nums, int size);
void displayList(const std::vector<int> &nums, std::string message);
void swapElements(std::vector<int> &nums, int index1, int index2);

int main() {
    int size;
    std::cout << "Enter how many numbers you want in the list: ";
    std::cin >> size;

    std::vector<int> numbers(size);

    // Input total number of integers in the list
    inputList(numbers, size);

    // Displays the list before swapping
    displayList(numbers, "Before swapping");

    // Asks which positions to swap
    int pos1, pos2;
    std::cout << "\nEnter first position to swap (0-based index): ";
    std::cin >> pos1;
    std::cout << "Enter second position to swap (0-based index): ";
    std::cin >> pos2;

    // Performs swapping
    swapElements(numbers, pos1, pos2);

    // Displays the list after swapping
    displayList(numbers, "After swapping");

    return 0;
}

// Function Definition

// Function to input list of numbers
void inputList(std::vector<int> &nums, int size) {
    std::cout << "\nEnter " << size << " numbers:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Number " << i << ": ";
        std::cin >> nums[i];
    }
}

// Function to display list of numbers
void displayList(const std::vector<int> &nums, std::string message) {
    std::cout << "\n" << message << ":" << std::endl;
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

// Function to swap two elements in the list
void swapElements(std::vector<int> &nums, int index1, int index2) {
    if (index1 >= 0 && index1 < nums.size() && index2 >= 0 && index2 < nums.size()) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    } else {
        std::cout << "Invalid indices for swapping!" << std::endl;
    }
}


