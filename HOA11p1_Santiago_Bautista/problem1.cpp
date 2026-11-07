
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

// Returns false if duplicate elements are found
bool Unique(const std::vector<int>& A) {
    int n = static_cast<int>(A.size());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    const int sizes[] = {100, 500, 1000, 2000};
    std::mt19937 generator(42);

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "PROBLEM 1\n\n";

    for (int size : sizes) {
        std::vector<int> A(size);

        // Generate unique values
        for (int i = 0; i < size; i++) {
            A[i] = i;
        }

        // Shuffle the values
        for (int i = size - 1; i > 0; i--) {
            std::uniform_int_distribution<int> dist(0, i);
            int j = dist(generator);
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

        auto start = std::chrono::steady_clock::now();

        bool result = Unique(A);

        auto end = std::chrono::steady_clock::now();

        double time =
            std::chrono::duration<double, std::micro>(
                end - start
            ).count();

        std::cout << "Input size: " << size << '\n';
        std::cout << "All elements unique: "
                  << (result ? "Yes" : "No") << '\n';
        std::cout << "Execution time: "
                  << time << " microseconds\n";
        std::cout << "---------------------------------------\n";
    }

    return 0;
}
