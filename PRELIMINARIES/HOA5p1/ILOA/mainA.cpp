#include<iostream>
#include<queue>

void displayAll(std::queue<char> copyQueue);

void isEmpty(std::queue<char> emptyQueue);

int main(){
    // Create an object
    std::queue<char> myQ;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Empty
    isEmpty(myQ);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Pushes Characters in the Queue
    myQ.push('N');
    myQ.push('I');
    myQ.push('N');
    myQ.push('Y');
    myQ.push('A');
    // Displays Queue
    displayAll(myQ);

    // Organizes Output
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Empty
    isEmpty(myQ);

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Size
    std::cout << "Queue size: " << myQ.size() << "\n";

    // Organizes Output
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Front
    std::cout << "Front of the Queue: " << myQ.front() << "\n";

    // Organizes Output
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Back
    std::cout << "Back of the Queue: " << myQ.back() << "\n";

    // Push
    myQ.push('H');

    // Display
    displayAll(myQ);

    // Organizes Output
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;

    // Pop
    std::cout << "Character to be popped: " << myQ.front() << "\n"; 
    myQ.pop();

    // Display
    displayAll(myQ);

    // Organizes Output
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< std::endl;



    return 0;
}

void displayAll(std::queue<char> copyQueue){
    // Creates a copy of the queue that was passed 
    std::queue<char> c = copyQueue; // Temporary Queue

    while(!c.empty()){
        std::cout << "" << c.front();
        c.pop();
    }
    std::cout << "\n";
}

void isEmpty(std::queue<char> emptyQueue){
        // Empty
    if (emptyQueue.empty()){
        std::cout << "Queue is Empty\n";
    }else{
        std::cout << "Queue is NOT Empty\n";
    }
}


