#ifndef SINGLY_LL_H
#define SINGLY_LL_H

//TEMPLATING
template <typename T>
class SinglyList{
    public:
        T data;
        SinglyList<T> *next = nullptr;

};

//TRAVERSAL
template <typename T>
void listTraversal(SinglyList<T>* head){

    if (head == nullptr){
        std::cout << "List is EMPTY" << std::endl;
        return;
    }

    while(head != nullptr){
        std::cout << head->data;
        if (head != nullptr){
            std::cout << "->";
        }
        head = head->next; 
    }
	std::cout << std::endl;
}

//INSERT HEAD
template <typename T>
void sllInsertHead(T newData, SinglyList<T>** currentHead){
    // 1. Allocate Memory for the new Data
    SinglyList<T>* newNode = new SinglyList<T>;
    // 2. Put our Data into the New Node
    newNode->data = newData;
    // 3. Set Next of the new Node to point to the previous Head
    newNode->next = *currentHead;
    // 4. Reset Head to point to the new Node
    *currentHead = newNode;

}

//GENERAL INSERT
template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode){
	// 2. If null, print "Previous node cannot be null.
	if (prevNode == nullptr){
		std::cout << "Previous Node cannot be Null" << std::endl;
		
	}
	// 3. Allocate a new node
	SinglyList<T>* newNode = new SinglyList<T>;
	// 4. Store data in the new node
	newNode->data = newData;
	// 5. Point new node to the node previous node was pointing to
	newNode->next = prevNode->next;
	// 6. Point previous node to the new node
	prevNode->next = newNode;
}

//INSERT END
template <typename T>
void sllInsertEnd(T newData, SinglyList<T>** head){
	//1. Allocate new node
	SinglyList<T>* newNode = new SinglyList<T>;
	//2. Dereference to the head node
	SinglyList<T>* currentNode = *head;
	//3. Store data in new node
	newNode->data = newData;
	//4. Point next of new node to nullptr
	newNode->next = nullptr;
	//5. Traverse the list until next of the node is null
	while(currentNode->next != nullptr){
		currentNode = currentNode->next;
		
	}
	//6. Point the next of the current node to the new node
	currentNode->next = newNode;
	
}

//DELETING NODE
template <typename T>
void sllDeleteNodes(T findData, SinglyList<T>** head){
	// Check if there is no list to be deleted.
	if(*head == nullptr) return;
	
	SinglyList<T>* currentNode = *head;
	SinglyList<T>* prevNode = nullptr;
	
	// Searching Loop
	while(currentNode != nullptr && currentNode->data != findData){
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	
	// Data was wa NOT found:
	if (currentNode == nullptr) return;
	
	//What if the Node to be deleted is the Head Node
	if(prevNode == nullptr){
		*head = currentNode->next;
	}else{
		prevNode->next = currentNode->next;
	}
	
	// We have to DELETE the Node
	delete currentNode;
	
	
}

//DELETE ALL NODES
template <typename T>
void sllDeleteList(SinglyList<T>** head){
	SinglyList<T>* current = *head;
	
	while(current->next != nullptr){
		SinglyList<T>* temp = current;
		current = current->next;
		delete temp;
	}
	*head = nullptr;
} 



#endif





