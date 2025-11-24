#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "DynQueue.h"
using namespace std;

template <class T>
class BinaryTree
{
private:
    struct TreeNode
    {
        T value;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    // priv member func
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void storeInOrder(TreeNode *nodePtr, DynQueue<T> &q) const;

public:
    BinaryTree() { root = nullptr; }
    
    void insertNode(T value);
    void fillQueueInOrder(DynQueue<T> &q) const;
};

// insert node in tree
template <class T>
void BinaryTree<T>::insertNode(T value)
{
    TreeNode *newNode = new TreeNode;
    newNode->value = value;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else 
        insert(nodePtr->right, newNode);
}

// store values in ascedning order
template <class T>
void BinaryTree<T>::storeInOrder(TreeNode *nodePtr, DynQueue<T> &q) const
{
    if (nodePtr)
    {
        storeInOrder(nodePtr->left, q);
        q.enqueue(nodePtr->value);
        storeInOrder(nodePtr->right, q);
    }
}

// public warpper
template <class T>
void BinaryTree<T>::fillQueueInOrder(DynQueue<T> &q) const
{
    storeInOrder(root, q);
}

#endif