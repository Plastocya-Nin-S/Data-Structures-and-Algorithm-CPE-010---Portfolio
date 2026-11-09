#include "queueARRchar.h"

int main() {
    QueueChar q(10);

    std::cout << "==============================" << std::endl;
    std::cout << "Is Empty? " << q.Empty() << std::endl;
    std::cout << "==============================" << std::endl;

    // Enqueue characters to form "NINYA"
    q.Enqueue('N');
    q.Enqueue('I');
    q.Enqueue('N');
    q.Enqueue('Y');
    q.Enqueue('A');
    q.Display();
    
    std::cout << "==============================" << std::endl;

    std::cout << "Front Element: " << q.Front() << std::endl;
    std::cout << "Back Element: " << q.Back() << std::endl;
    std::cout << "Size of Queue: " << q.Size() << std::endl;

    std::cout << "==============================" << std::endl;

    // Pop one character
    std::cout << "Character to be popped: " << q.Front() << std::endl;
    q.Dequeue();
    q.Display();

    std::cout << "==============================" << std::endl;

    // Add another character
    q.Enqueue('H');
    std::cout << "After Enqueue 'H': ";
    q.Display();

    std::cout << "==============================" << std::endl;

    // Clear queue
    q.Clear();
    std::cout << "After Clear -> ";
    q.Display();

    std::cout << "==============================" << std::endl;

    return 0;
}

