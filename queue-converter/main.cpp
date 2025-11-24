//
// Jose Garcia
// 11/23/25
// Queue Converter Programming Project
// COSC 2030
//

#include <iostream>
#include "BinaryTree.h"
#include "DynQueue.h"
using namespace std;

int main()
{
    BinaryTree<int>tree;
    DynQueue<int> q;
    int value;

    // insert number into tree
    cout << "Inserting the values 5, 8, 12, 1, 9, 3...\n";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(12);
    tree.insertNode(1);
    tree.insertNode(9);
    tree.insertNode(3);

    // transfer values from tree to queue, ascending order

    tree.fillQueueInOrder(q);

    // dequeue, display values
    cout << "\nThe values in ascending order:\n";
    while (!q.isEmpty())
    {
        q.dequeue(value);
        cout << value << " ";
    }

    cout << endl << endl;

    return 0;
}