#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
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

    //priv member func
    void insert (TreeNode *&nodePtr, TreeNode *&newNode);
    void remove (TreeNode *&nodePtr, T value);
    void makeDeletion(TreeNode *&nodePtr);
    void displayInOrder(TreeNode *nodePtr) const;
    int countNodes(TreeNode *nodePtr) const;

public:
    //constructor
    BinaryTree() { root = nullptr; }

    // public wrapper func
    void insertNode(T vallue);
    void remove(T value);
    void displayInOrder() const;
    int numNodes() const;
};

// insertNode

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

// remove

template <class T>
void BinaryTree<T>::remove(T value)
{
    remove(root, value);
}

template <class T>
void BinaryTree<T>::remove(TreeNode *&nodePtr, T value)
{
    if (nodePtr == nullptr)
        return;
    else if (value <nodePtr->value)
        remove(nodePtr->left, value);
    else if (value > nodePtr->value)
        remove(nodePtr->right, value);
    else
        makeDeletion(nodePtr);
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr;

    if (nodePtr == nullptr)
        return;
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

// Display

template <class T>
void BinaryTree<T>::displayInOrder() const
{
    displayInOrder(root);
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

// the numNodes func return number of nodes in tree

template <class T>
int BinaryTree<T>::numNodes() const
{
    return countNodes(root);
}

// countNodes function uses nodes in
// the tree. This function is called
// by the public member fucntion numNodes

template <class T>
int BinaryTree<T>::countNodes(TreeNode *nodePtr) const
{
    if (nodePtr == NULL)
        return 0;
    else
        return 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
}

#endif 