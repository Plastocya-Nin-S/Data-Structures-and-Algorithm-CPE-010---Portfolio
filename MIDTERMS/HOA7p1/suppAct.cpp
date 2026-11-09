#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"

const int max_size = 100;

int main (){
    int testArray[max_size];

    // CANDIDATE LIST
    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Layla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    // DISPLAYING THE CANDIDATES
    std::cout << "===== LIST OF CANDIDATES =====\n";

    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << i + 1 << ": "
                  << candidates[i] << "\n";
    }

    std::cout << "\n";

    srand(time(0)); // Seed the random number generator

    //GENERATING THE VOTES
    for (int i = 0; i < max_size; i++) {    
        testArray[i] = std::rand() % 5 + 1; // Values represent candidates 1 to 5
    }

    //DISPLAYING THE VOTES(ARRAY)
    std::cout<<"Array elements:\n";
    displayArray(testArray, max_size);

    //SORTING THE VOTES
    std::cout<<"\n\nSorting the votes using Selection Sort...\n";
    selectionSort(testArray, max_size);
    displayArray(testArray, max_size);

    int winnerCand = 1;
    int highestVotes = 0;

    //SEARCHING FOR EACH CANDIDATE'S VOTES
    std::cout << "\n\nVote count:\n";

    for (int candidate = 1; candidate <= 5; candidate++) {
        int votes = CountVotes(testArray, max_size, candidate);

        std::cout << "Candidate " << candidate << " - "
                  << candidates[candidate - 1] << ": "<< votes << " votes\n";

        if (votes > highestVotes) {
            highestVotes = votes;
            winnerCand = candidate;
        }
    }

    // DISPLAYING THE WINNING CANDIDATE
    std::cout << "\nWinner: Candidate " << winnerCand;
    std::cout << " with " << highestVotes << " votes\n";

    return 0;
}

