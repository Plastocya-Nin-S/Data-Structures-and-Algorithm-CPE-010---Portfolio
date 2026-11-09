#include <iostream>
#include <string>
#include <thread>

void print(int n, const std::string &str) {
    std::cout << "=================================" << std::endl;
    std::cout << "Printing integer: " << n << std::endl;
    std::cout << "Printing string: " << str << std::endl;
    std::cout << "=================================" << std::endl;
}

int main() {
    std::thread t1(print, 2026, "T.I.P. - QC");
    t1.join();
    return 0;
}
