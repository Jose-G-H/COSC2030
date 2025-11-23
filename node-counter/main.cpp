//
// Jose Garcia
// 11/23/25
// Node Counter Programming Project
// COSC 2030
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    // create binary tree to hold integers
    BinaryTree<int> tree;

    // Insert some nodes into tree
    cout << "Inserting nodes.\n";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);

    // get number of nodes
    cout << "\nNumber of nodes: "
         << tree.numNodes() << endl;
    cout << "\nHere are the values in the tree:\n";

    // Display the tree
    tree.displayInOrder();
    cout << endl;

    // Delete some nodes from tree
    cout << "Deleting 8...\n";
    tree.remove(8);
    cout << "Deleting 12...\n";
    tree.remove(12);

    // get number of nodes
    cout << "\nNumber of nodes: "
         << tree.numNodes() << endl;

    // Display nodes
    cout << "Now, here are the nodes:\n";
    tree.displayInOrder();
    cout << endl;

    return 0;
}