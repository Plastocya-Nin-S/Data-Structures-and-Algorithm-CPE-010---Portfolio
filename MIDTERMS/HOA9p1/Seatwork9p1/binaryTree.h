#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

template<typename T>
class BinaryTree{
    private:
        // Key
        T key;

        // Pointers left child and right child
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;

    public:
        // Constructor
        BinaryTree(T rootObj);

        // Insert left & right Child
        void insertLeftChild(T newNode);
        void insertRightChild(T newNode);

        // To Access the child Nodes
        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();

        // Get root value & set root node
        T getRootValue();
        void setRootValue(T obj);

        //node checker if leaf
        bool isLeaf();

        // Deletion of a node
        void deleteNode(T obj);

        // Deletion of the whole tree
        void deleteTree();
};
//=====================================================================
// Constructor
template<typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
}

//=====================================================================
// Insert left Child & right Child
template<typename T>
void BinaryTree<T>::insertLeftChild(T newNode){
    // Has 2 types:
    // 1. If left child is nullptr, create a new node
    if (leftChild == nullptr){
        leftChild = new BinaryTree<T>(newNode);
    }
    // 2. If we want to insert a certain node
    else{
        // Create a new node:
        BinaryTree<T>* newChild = new BinaryTree<T>(newNode);
        // Set the new node's left child to the current left child
        newChild->leftChild = leftChild;
        // Set the current left child to the new node
        leftChild = newChild;
    }
}
 
template<typename T>
void BinaryTree<T>::insertRightChild(T newNode){
    // Has 2 types:
    // 1. If right child is nullptr, create a new node
    if (rightChild == nullptr){
        rightChild = new BinaryTree<T>(newNode);
    }
    // 2. If we want to insert a certain node
    else{
        // Create a new node:
        BinaryTree<T>* newChild = new BinaryTree<T>(newNode);
        // Set the new node's right child to the current right child
        newChild->rightChild = rightChild;
        // Set the current right child to the new node
        rightChild = newChild;
    }

}

//=====================================================================
// To Access the child Nodes
template<typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild(){
    return leftChild;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild(){
    return rightChild;
}

//=====================================================================
// Get root value & set root node
template<typename T>
T BinaryTree<T>::getRootValue(){
    return key;
}

template<typename T>
void BinaryTree<T>::setRootValue(T obj){
    key = obj;
}

//=====================================================================
// Check if the node is a leaf
template<typename T>
bool BinaryTree<T>::isLeaf(){
    return (leftChild == nullptr && rightChild == nullptr);
}

//=====================================================================
// Deletion of a node
template<typename T>
void BinaryTree<T>::deleteNode(T obj){
    if (leftChild != nullptr){
        if (leftChild->key == obj){
            leftChild->deleteTree();
            delete leftChild;
            leftChild = nullptr;
            return;
        }
        else{
            leftChild->deleteNode(obj);
        }
    }

    if (rightChild != nullptr){
        if (rightChild->key == obj){
            rightChild->deleteTree();
            delete rightChild;
            rightChild = nullptr;
            return;
        }
        else{
            rightChild->deleteNode(obj);
        }
    }
}

//=====================================================================
// Deletion of the whole tree
template<typename T>
void BinaryTree<T>::deleteTree(){
    if (leftChild != nullptr){
        leftChild->deleteTree();
        delete leftChild;
        leftChild = nullptr;
    }

    if (rightChild != nullptr){
        rightChild->deleteTree();
        delete rightChild;
        rightChild = nullptr;
    }
}
//=====================================================================

#endif