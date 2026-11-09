#ifndef QUEUELL_H
#define QUEUELL_H

// Create a Class for the Node
template <typename T>
class qNode{
    public:
    T data;
    qNode<T>* next;
};

// Creates the New Node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// Enqueue Operation
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    // Create new node
    qNode<T>* newNode = new_node(newData);

    // Inserting into an empty queue
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){ // Checks if Queue is Empty
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }

    // Inserting into a non-empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

// Dequeue Operation
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    // Adds a Check if the queue is already empty
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        std::cout << "Queue is EMPTY" << std::endl;
    }

    // Create a Temporary node
    qNode<T>* deleteNode = nullptr; // Temporary Variable
    deleteNode = (*frontPtr);

    // Check if the queue has only one node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    // Delete the Node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

// Checks the Front
template <typename T>
void frontCheck(qNode<T>** frontPtr, qNode<T>** backPtr){
    // Checks if the queue is empty
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
    std::cout << "Queue is EMPTY" << std::endl;
    }

    // Access the front node data/pointer
    qNode<T>* front = *frontPtr;
    std::cout << "Front Element: " << front->data << std::endl;
}

// Checks the Back
template <typename T>
void backCheck(qNode<T>** frontPtr, qNode<T>** backPtr){
    // Checks if the queue is empty
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
    std::cout << "Queue is EMPTY" << std::endl;
    }

    // Access the front node data/pointer
    qNode<T>* back = *backPtr;
    std::cout << "Back Element: " << back->data << std::endl;
}


// Display All
template <typename T>
void displayAll(qNode<T> **frontPtr, qNode<T> **backPtr){
    // Checks if queue is Empty
        if((*frontPtr) == nullptr && (*backPtr) == nullptr){
           std::cout << "The queue is empty!" << std::endl;
           return;
        }
        
    // Traverse through the queue to Display All
    std::cout << "Displaying the Entire queue: " << std::endl;    
    while ((*frontPtr) != nullptr){
        std::cout << (*frontPtr)->data << " ";
        (*frontPtr) = (*frontPtr)->next;
    }
    std::cout<<std::endl;
}

#endif


