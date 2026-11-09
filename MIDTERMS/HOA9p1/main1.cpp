#include <iostream>
#include "BinarySearchTree.h"

int main(){

    BinarySearchTree<int>* tree = new BinarySearchTree(2);

    tree->insert(2)
    tree->insert(3);
    tree->insert(9);
    tree->insert(18);
    tree->insert(0);
    tree->insert(1);
    tree->insert(4);
    tree->insert(5);

    std::cout<<"Pre Order Output: ";
    tree->preOrder();
    std::cout<<std::endl;

    std::cout<<"In Order Output: ";
    tree->inOrder();
    std::cout<<std::endl;

    std::cout<<"Post Order Output: ";
    tree->postOrder();
    std::cout<<std::endl;

    return 0;
}