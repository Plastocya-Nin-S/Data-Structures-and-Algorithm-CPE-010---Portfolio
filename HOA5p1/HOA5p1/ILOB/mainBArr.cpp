#include <iostream>
#include "queueLL.h"
#include "queueARR.h"

int main() {

    // Create an Object
    QueueArr<int> q(6);

    std::cout << "====================================================================" << std::endl;

    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Enqueue(4);
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Enqueue(5);
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Enqueue(6);
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Enqueue(7);
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;

    std::cout << "====================================================================" << std::endl;

    q.DisplayAll();

    std::cout << "\n====================================================================" << std::endl;

    q.Dequeue();
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Dequeue();
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Dequeue();
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Clear();
    std::cout<<"q_front: " << q.Front() <<" q_back: " <<q.Back() << " q_size: " <<q.Size()<<std::endl;
    q.Dequeue();

    std::cout << "====================================================================" << std::endl;

    q.DisplayAll();

    std::cout << "====================================================================" << std::endl;

    return 0;
}

