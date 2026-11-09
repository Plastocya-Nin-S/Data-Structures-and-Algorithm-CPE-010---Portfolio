#include <iostream>
#include "functions.h"

int main() {
    int x[] = {1, 2, 3, 4, 5};
    int y[] = {6, 7, 8, 9, 10};

    int n = 5;
    int m = 5;

    if (different(x, y, n, m)) {
        std::cout << "The arrays have no common values." << std::endl;
    }
    else {
        std::cout << "The arrays have common values." << std::endl;
    }

    return 0;
}
