#include <iostream>
#include "singly_LL.h"

int main(){

    // Creating an Empty List
    SinglyList<char>* head = new SinglyList<char>;
    SinglyList<char>* second = new SinglyList<char>;
    SinglyList<char>* third = new SinglyList<char>;
    SinglyList<char>* fourth = new SinglyList<char>;
    SinglyList<char>* fifth = new SinglyList<char>;

    // Assign the Data
    head->data = 'N';
    head->next = second;

    second->data = 'I';
    second->next = third;

    third->data = 'N';
    third->next = fourth; 

    fourth->data = 'Y';
    fourth->next = fifth;

    fifth->data = 'A';
    fifth->next = NULL;

    std::cout << head->data << second->data << std::endl;
    std::cout << head->next << second->next->data << std::endl;

    std::cout << "================================" << std::endl;

    listTraversal(head); 

    std::cout << "================================" << std::endl;
    
    std::cout << "Inserting a New Node at the Head: \n" << std::endl;
    sllInsertHead('S', &head);
    listTraversal(head);

    std::cout << "================================" << std::endl;
    
	std::cout << "Inserting a New Node at the third: \n" << std::endl;
	sllGeneralInsert('U', head->next->next);
	listTraversal(head);
	
    std::cout << "================================" << std::endl; 

	std::cout << "Inserting a New Node at the End: \n" << std::endl;
	sllInsertEnd('H', &head);
	listTraversal(head);

    std::cout << "================================" << std::endl;
	
	std::cout << "Deleting a Node: \n" << std::endl;
	sllDeleteNodes('U', &head);
	listTraversal(head);

    std::cout << "================================" << std::endl;
	
	std::cout << "Deleting the Head Node: \n" << std::endl;
	sllDeleteNodes('S', &head);
	listTraversal(head);

    std::cout << "================================" << std::endl;
	
	std::cout << "Deleting all the Nodes: \n" << std::endl;
	sllDeleteList(&head);
	listTraversal(head);

    std::cout << "================================" << std::endl;

    return 0;
}



