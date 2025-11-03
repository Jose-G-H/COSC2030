//
// Jose Garcia
// 11/02/25
// List Print Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

class LinkedList
{
private:
    // structure for nodes
    struct ListNode
    {
        int value;
        ListNode *next;
    };

    ListNode *head;

public:
    // constructor
    LinkedList()
    {  head = nullptr; }

    // destructor
    ~LinkedList()
    {   destroyList();  }

    // append node to the end of list
    void appendNode(int num)
    {
        ListNode *newNode;
        ListNode *nodePtr;

        // allocate new node and store num
        newNode = new ListNode;
        newNode->value = num;
        newNode->next = nullptr;

        // list is empty, make newNode first node
        if (!head)
            head = newNode;
        else
        {
            nodePtr = head;

            // find last node in list
            while (nodePtr->next)
                nodePtr = nodePtr->next;

            // newNode as last node
            nodePtr->next = newNode;
        }
    }
    // function print all values in list
    void print() const
    {
        ListNode *nodePtr = head;

        cout << "Contents in list: ";
        while (nodePtr)
        {
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
private:
    // destructor helper function
    void destroyList()
    {
        ListNode *nodePtr = head;
        ListNode *nextNode;

        while (nodePtr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
        head = nullptr;
    }
};

// LinkedList class test
int main()
{
    LinkedList list;
    cout << "Starting with empty list...\n";
    list.print();

    cout << "\nAdding the elements 2, 4, 6, 8...\n";
    list.appendNode(2);
    list.appendNode(4);
    list.appendNode(6);
    list.appendNode(8);

    cout << "\nPrinting the updated list:\n";
    list.print();

    cout << "\nEnd of program.\n";
    return 0;
}
