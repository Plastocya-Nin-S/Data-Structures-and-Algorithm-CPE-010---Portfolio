#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

//TEMPLATING
template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T> *next = nullptr;
        DoubleList<T> *prev = nullptr;

};

// Function to Create a new node
template <typename T>
DoubleList<T>* createNode(T newData) {
    // Dynamically allocate memory for the new node
    DoubleList<T>* newNode = new DoubleList<T>;
    
    newNode->data = newData; 
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the address of the new node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T> *currentNode) {

    DoubleList<T> *tail = nullptr; 
    
    // Checking if the list is empty 
    if (currentNode == nullptr) {
        std::cout << "List is EMPTY" << std::endl;
    }

    // Forward Traversal
    std::cout << "Forward Traversal: " << std::endl;
    // Moves toward the last node ( before the null )
    while (currentNode != nullptr) {
        // Printed the data
        std::cout << currentNode->data << " ";
        // Saved the current node as the last visited node
        tail = currentNode;  // Keep track of the last node for backward traversal
        // Moves to the next node in the list
        currentNode = currentNode->next;
    }

    //  Backward Traversal
    std::cout << std::endl << "Backward Traversal: " << std::endl;
    // Moves toward the head
    while (tail != nullptr) {
        // Printed the data
        std::cout << tail->data << " ";
        // Move to the previous node in the list
        tail = tail->prev;
    }
    std::cout << std::endl;

}

    template <typename T>
    void dllInsertHead(T newData, DoubleList<T>** currentHead) {
        // Create a new node with the given data
        DoubleList<T>* newNode = createNode(newData);
        // If the list is empty, make the new node the head
        if (*currentHead == nullptr) {
            *currentHead = newNode;
            return;
        }
        // Link the new node to the current head
        newNode->next = *currentHead;
        (*currentHead)->prev = newNode;

        // Update the head to point to the new node
        *currentHead = newNode;
    }

    // Insertion at the end of the list
    template <typename T>
    void dllInsertTail(T newData, DoubleList<T> *currentHead){
    //create
    DoubleList<T>* newNode = createNode(newData);
    //traverse
        while (currentHead->next != nullptr){
            currentHead = currentHead->next;
        }
        //connect last -> new
        currentHead->next = newNode;
        //connect new -> last
        newNode->prev = currentHead;;
        std::cout << std::endl;
    }

    // Insertion at any position/node
    template <typename T>
    void dllGeneralInsert(T newData, DoubleList<T>* prevNode, DoubleList<T>* nextNode){
        // Allocate/Create a newNode
        DoubleList<T>* newNode = createNode(newData);
        // Checks if the previous Node is Null, If yes, Print "Previous Node Cannot be NULL" 
        if (prevNode == nullptr) {
            std::cout << "Previous Node cannot be NULL" << std::endl;
            delete newNode;
            return;
        }
        // Point the new node to the node that the previous node was pointing to
        newNode->next = nextNode;
        // Set the previous pointer of the new node to the previous node
        newNode->prev = prevNode; 
        // Point the previous node to the new node
        prevNode->next = newNode;   
        if (nextNode != nullptr) {
            nextNode->prev = newNode; // Update the previous pointer of the next node
        }
    }

    // Deletion of a node
    template <typename T>
    void dllDeleteNodes(T findData, DoubleList<T>** currentHead) {
        // If the list is empty, return
        if (*currentHead == nullptr) {
            std::cout << "List is EMPTY" << std::endl;
            return;
        }

        DoubleList<T>* currentNode = *currentHead;

        // Traverse the list to find the node to delete
        while (currentNode != nullptr && currentNode->data != findData) {
            currentNode = currentNode->next;
        }

        // If the node was not found, return
        if (currentNode == nullptr) {
            std::cout << "Node with data " << findData << " not found." << std::endl;
            return;
        }

        if (currentNode == *currentHead) {
            *currentHead = currentNode->next;
            if (*currentHead) (*currentHead)->prev = nullptr;
        } else {
            currentNode->prev->next = currentNode->next;
            if (currentNode->next) currentNode->next->prev = currentNode->prev;
        }

        delete currentNode;
    }


#endif // DOUBLE_LL_H

