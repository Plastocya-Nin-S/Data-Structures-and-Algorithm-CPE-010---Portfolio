#include <iostream>

const int SIZE = 4;

int countPaths(int matrix[SIZE][SIZE], int row, int col,
               int totalCost, int targetCost) {
    // Check if the position is outside the matrix
    if (row >= SIZE || col >= SIZE) {
        return 0;
    }

    // Add the current cell's cost
    totalCost += matrix[row][col];

    // Check if the destination is reached
    if (row == SIZE - 1 && col == SIZE - 1) {
        if (totalCost == targetCost) {
            return 1;
        }
        return 0;
    }

    // Move right and move down
    int right = countPaths(matrix, row, col + 1,
                           totalCost, targetCost);

    int down = countPaths(matrix, row + 1, col,
                          totalCost, targetCost);

    // Return the total number of valid paths
    return right + down;
}

int main() {
    int matrix[SIZE][SIZE] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost;

    std::cout << "Matrix:" << std::endl;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nEnter target cost: ";
    std::cin >> targetCost;

    int result = countPaths(matrix, 0, 0, 0, targetCost);

    std::cout << "Number of paths with cost "
              << targetCost << ": " << result << std::endl;

    return 0;
}
