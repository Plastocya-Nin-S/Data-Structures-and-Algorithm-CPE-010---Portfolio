#include <iostream>
#include "queueARR.h"

int main() {
    Queue q(5);

    std::cout << "==============================" << std::endl;
    std::cout << "Is the Queue Empty? " << q.Empty() << std::endl;
    std::cout << "==============================" << std::endl;

    q.Enqueue(05);
    q.Enqueue(01);
    q.Enqueue(26);
    q.Display();

    std::cout << "==============================" << std::endl;
    std::cout << "Front Element: " << q.Front() << std::endl;
    std::cout << "Back Element: " << q.Back() << std::endl;
    std::cout << "Size of Array: " << q.Size() << std::endl;
    std::cout << "==============================" << std::endl;

    q.Dequeue();
    q.Display();

    std::cout << "==============================" << std::endl;

    q.Enqueue(8);
    q.Enqueue(10);
    q.Display();

    std::cout << "==============================" << std::endl;

    q.Clear();
    std::cout << "After Clear Operation: " << std::endl;
    q.Display();

    std::cout << "==============================" << std::endl;

    return 0;
}
