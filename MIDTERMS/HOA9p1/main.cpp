#include <iostream>
#include "Tree.h"

int main() {
    // Task 1: Building tree nodes using your BST class style
    BinarySearchTree<char>* tree = new BinarySearchTree<char>('A');

    // Create child nodes
    BinarySearchTree<char>* nodeB = new BinarySearchTree<char>('B');
    BinarySearchTree<char>* nodeC = new BinarySearchTree<char>('C');
    BinarySearchTree<char>* nodeD = new BinarySearchTree<char>('D');
    BinarySearchTree<char>* nodeE = new BinarySearchTree<char>('E');
    BinarySearchTree<char>* nodeF = new BinarySearchTree<char>('F');
    BinarySearchTree<char>* nodeG = new BinarySearchTree<char>('G');
    BinarySearchTree<char>* nodeH = new BinarySearchTree<char>('H');
    BinarySearchTree<char>* nodeI = new BinarySearchTree<char>('I');
    BinarySearchTree<char>* nodeJ = new BinarySearchTree<char>('J');
    BinarySearchTree<char>* nodeK = new BinarySearchTree<char>('K');
    BinarySearchTree<char>* nodeL = new BinarySearchTree<char>('L');
    BinarySearchTree<char>* nodeM = new BinarySearchTree<char>('M');
    BinarySearchTree<char>* nodeN = new BinarySearchTree<char>('N');
    BinarySearchTree<char>* nodeP = new BinarySearchTree<char>('P');
    BinarySearchTree<char>* nodeQ = new BinarySearchTree<char>('Q');

    tree->addChild(nodeB);
    tree->addChild(nodeC);
    tree->addChild(nodeD);
    tree->addChild(nodeE);
    tree->addChild(nodeF);
    tree->addChild(nodeG);

    nodeD->addChild(nodeH);
    nodeE->addChild(nodeI);
    nodeE->addChild(nodeJ);
    nodeF->addChild(nodeK);
    nodeF->addChild(nodeL);
    nodeF->addChild(nodeM);
    nodeG->addChild(nodeN);
    nodeJ->addChild(nodeP);
    nodeJ->addChild(nodeQ);

    // Task 3.2: Output Traversals
    std::cout << "Pre Order Output: ";
    tree->preOrder();
    std::cout << std::endl;

    std::cout << "In Order Output: ";
    tree->inOrder();
    std::cout << std::endl;

    std::cout << "Post Order Output: ";
    tree->postOrder();
    std::cout << std::endl << std::endl;

    // Task 3.3: findData function test
    tree->findData("Pre-Order", 'P', tree);
    std::cout << std::endl;

    // Task 3.4: Add node 'O' as child of 'G' and search
    BinarySearchTree<char>* nodeO = new BinarySearchTree<char>('O');
    nodeG->addChild(nodeO);

    tree->findData("Pre-Order", 'O', tree);

    return 0;
}










