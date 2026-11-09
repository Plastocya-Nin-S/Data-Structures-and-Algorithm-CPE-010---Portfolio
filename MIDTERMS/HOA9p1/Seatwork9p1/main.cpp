#include <iostream>
#include "binaryTree.h"

/* 
               A
             /   \
            B     C
           / \   / \
          D   E F   NULLPTR

*/

int main(){
    std::cout << "Binary Tree Implementation" << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Call the constructor to create the root node
    BinaryTree<char>* root = new BinaryTree<char>('A');
    std::cout << "Root Value: " << root->getRootValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Creating the child of node A
    root->insertLeftChild('B');
    root->insertRightChild('C');

    std::cout << "Left Child of root A: " << root->getLeftChild()->getRootValue() << std::endl;
    std::cout << "Right Child of root A: " << root->getRightChild()->getRootValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Creating the child of node B
    root->getLeftChild()->insertLeftChild('D');
    root->getLeftChild()->insertRightChild('E');

    std::cout << "Left Child of root B: " << root->getLeftChild()->getLeftChild()->getRootValue() << std::endl;
    std::cout << "Right Child of root B: " << root->getLeftChild()->getRightChild()->getRootValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Creating the child of node C
    root->getRightChild()->insertLeftChild('F');
    root->getRightChild()->insertRightChild('G');

    std::cout << "Left Child of root C: " << root->getRightChild()->getLeftChild()->getRootValue() << std::endl;
    std::cout << "Right Child of root C: " << root->getRightChild()->getRightChild()->getRootValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Insertion 
    root->insertLeftChild('X');
    std::cout << "New Left Child of root A: " << root->getLeftChild()->getRootValue() << std::endl;
    std::cout << "New Left Child of root X: " << root->getLeftChild()->getLeftChild()->getRootValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Set the root value of node A
    root->setRootValue('Z');
    std::cout << "New Root Value of Node A: " << root->getRootValue() << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Check if nodes are leaves
    std::cout << "Is Node A a leaf? " << (root->isLeaf() ? "Yes" : "No") << std::endl;
    std::cout << "Is Node C a leaf? " << (root->getRightChild()->isLeaf() ? "Yes" : "No") << std::endl;
    std::cout << "Is Node F a leaf? " << (root->getRightChild()->getLeftChild()->isLeaf() ? "Yes" : "No") << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    std::cout << "\n________________________________________________________________________" << std::endl;
    // Deletion of a node
    root->deleteNode('X');
    std::cout << "After deleting node X, Left Child of root A: ";
    if (root->getLeftChild() == nullptr){
        std::cout << "There is no left child." << std::endl;
    }else{
        std::cout << root->getLeftChild()->getRootValue() << std::endl;
    }

    // Deletion of the whole tree
    root->deleteTree();

    delete root;
    root = nullptr;
    std::cout << "Everything has been deleted." << std::endl;

    if (root == nullptr){
        std::cout << "There is no present root." << std::endl;
    }
    std::cout << "________________________________________________________________________" << std::endl;

    return 0;
}