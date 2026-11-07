#include <iostream>

//This computes the total sum of all the quizzes
int totalSum(int x, int y, int z) {
    int total = x + y + z;
    std::cout << "Total: " << total << "\n";
    return total; /* This sends the total to its call and also allows this function 
	              to be called in another function.*/
}

//This computes the Average of the Quizzes Scores
void quizAverage(int total) {
    int average = total / 3;
    std::cout << "Average: " << average << "\n";
}


int main () {
    int x, y, z;


    std::cout << "Enter Your Scores from Quiz 1 to Quiz 3 (Separated by Spaces): " ;
    std::cin >> x >> y >> z; //This inputs all three scores


    int total = totalSum (x, y, z);


    quizAverage(total);


    return 0;
}


