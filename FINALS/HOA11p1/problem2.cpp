
#include <iostream>
#include <chrono>
#include <iomanip>

// Regular recursive power: O(n)
long long rpower(int x, int n) {
    if (n == 0) {
        return 1;
    }

    return x * rpower(x, n - 1);
}

// Binary recursive power: O(log n)
long long brpower(int x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    long long y = brpower(x, n / 2);
    return y * y;
}

int main() {
    const int base = 2;
    const int exponents[] = {5, 10, 15, 20};

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "PROBLEM 2\n\n";

    for (int n : exponents) {
        auto start1 = std::chrono::steady_clock::now();
        volatile long long result1 = rpower(base, n);
        auto end1 = std::chrono::steady_clock::now();

        double time1 =
            std::chrono::duration<double, std::micro>(
                end1 - start1
            ).count();

        auto start2 = std::chrono::steady_clock::now();
        volatile long long result2 = brpower(base, n);
        auto end2 = std::chrono::steady_clock::now();

        double time2 =
            std::chrono::duration<double, std::micro>(
                end2 - start2
            ).count();

        std::cout << "Base: " << base
                  << ", Exponent: " << n << '\n';

        std::cout << "rpower result: " << result1 << '\n';
        std::cout << "rpower time: "
                  << time1 << " microseconds\n";

        std::cout << "brpower result: " << result2 << '\n';
        std::cout << "brpower time: "
                  << time2 << " microseconds\n";

        std::cout << "----------------------------------\n";
    }

    return 0;
}
