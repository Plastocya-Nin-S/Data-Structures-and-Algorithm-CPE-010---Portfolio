#ifndef Tree_H
#define Tree_H

#include <iostream>
#include <string>

template <typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree<T>* firstChild;   
    BinarySearchTree<T>* nextSibling;  

    bool searchTree(BinarySearchTree<T>* node, T target) {
        if (node == nullptr) return false;
        if (node->key == target) return true;
        if (searchTree(node->firstChild, target)) return true;
        return searchTree(node->nextSibling, target);
    }

public:
    BinarySearchTree(T value);
    void addChild(BinarySearchTree<T>* child);
    BinarySearchTree<T>* findNode(T value);

    // Traversal algorithms
    void preOrder();
    void inOrder();
    void postOrder();

    // Search algorithm
    void findData(std::string choice, T target, BinarySearchTree<T>* root);
};

// Constructor implementation
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

// Add a child node
template <typename T>
void BinarySearchTree<T>::addChild(BinarySearchTree<T>* child) {
    if (firstChild == nullptr) {
        firstChild = child;
    } else {
        BinarySearchTree<T>* temp = firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

// Find node pointer by key
template <typename T>
BinarySearchTree<T>* BinarySearchTree<T>::findNode(T value) {
    if (key == value) return this;
    BinarySearchTree<T>* result = nullptr;
    if (firstChild != nullptr) result = firstChild->findNode(value);
    if (result == nullptr && nextSibling != nullptr) result = nextSibling->findNode(value);
    return result;
}

// Pre-Order Traversal (Root -> Children)
template <typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << key << "    ";
    if (firstChild != nullptr) {
        firstChild->preOrder();
    }
    if (nextSibling != nullptr) {
        nextSibling->preOrder();
    }
}

// In-Order Traversal 
template <typename T>
void BinarySearchTree<T>::inOrder() {
    if (firstChild != nullptr) {
        firstChild->inOrder();
    }
    std::cout << key << "    ";
    if (nextSibling != nullptr) {
        nextSibling->inOrder();
    }
}

// Post-Order Traversal 
template <typename T>
void BinarySearchTree<T>::postOrder() {
    if (firstChild != nullptr) {
        firstChild->postOrder();
    }
    std::cout << key << "    ";
    if (nextSibling != nullptr) {
        nextSibling->postOrder();
    }
}

// findData method
template <typename T>
void BinarySearchTree<T>::findData(std::string choice, T target, BinarySearchTree<T>* root) {
    std::cout << "Searching for '" << target << "' using [" << choice << "] traversal...\n";
    std::cout << "Traversal path: ";
    if (choice == "pre-order") {
        root->preOrder();
    } else if (choice == "in-order") {
        root->inOrder();
    } else if (choice == "post-order") {
        root->postOrder();
    }
    std::cout << std::endl;

    if (searchTree(root, target)) {
        std::cout << "\"" << target << " was found!\"\n";
    }
}

#endif

