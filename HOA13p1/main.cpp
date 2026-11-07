
#include <iostream>
#include <thread>
#include <mutex>
#include <string>

// Global variable
int globalVar = 0;
std::mutex mtx;

// Function that adds a value to the global variable
void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    globalVar += value;
}

// Function to display the global variable
void display(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << message << globalVar << std::endl;
}

int main() {
    // Create three threads
    std::thread T1(add, 15);
    std::thread T2(add, 25);
    std::thread T3(add, 35);

    // Display the current value
    display("Initial display: ");

    // Wait for Thread 1
    T1.join();
    display("After T1.join(): ");

    // Wait for Thread 2
    T2.join();
    display("After T2.join(): ");

    // Wait for Thread 3
    T3.join();
    display("After T3.join(): ");

    return 0;
}


