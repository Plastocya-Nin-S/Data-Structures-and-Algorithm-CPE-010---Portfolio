#include<iostream>
#include"queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    // For Organization Purposes 
    std::cout << "==========================================" << std::endl;

    // Enqueue Operation Testing:
    enqueue('N', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('I', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('N', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('S', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;

    // For Organization Purposes 
    std::cout << "==========================================" << std::endl;

    // Front Check Operation Testing:
    frontCheck(&front, &back);

    // For Organization Purposes 
    std::cout << "==========================================" << std::endl;

    // Back Check Operation Testing:
    backCheck(&front, &back);

    // For Organization Purposes 
    std::cout << "==========================================" << std::endl;

    // Dequeue Operation Testing:
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    dequeue(&front, &back);    
    dequeue(&front, &back);   


    return 0;
}

