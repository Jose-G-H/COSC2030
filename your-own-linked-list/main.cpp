//
// Jose Garcia
// 11/02/2025
// Your Own Linked List Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

class LinkedList
{
private:
    // struture for nodes
    struct ListNode
    {
        int value; // node data
        ListNode *next; // pointer to next node
    };

    ListNode *head; // head of list

public:
    // constructor
    LinkedList()
    {  head = nullptr; }

    // destrcutor 
    ~LinkedList()
    {  destroyList();  }

    // fucntion appends node to the end 
    void appendNode(int num)
    {
        ListNode *newNode;
        ListNode *nodePtr;

        // allocate new node and store num
        newNode = new ListNode;
        newNode->value = num;
        newNode->next = nullptr;

        // list is empty then make newnode first node
        if (!head)
            head = newNode;
        else
        {
            // nodePtr to head of list
            nodePtr = head;

            // find last node is list
            while (nodePtr->next)
                nodePtr = nodePtr->next;
            
            // newNode as last node
            nodePtr->next = newNode;
        }
    }
    // fucntion inserts node in order
    void insertNode(int num)
    {
        ListNode *newNode;
        ListNode *nodePtr;
        ListNode *previousNode = nullptr;

        newNode = new ListNode;
        newNode->value = num;
        // list is empty or new node is before head
        if (!head || head->value >= num)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            nodePtr = head;

            while (nodePtr != nullptr && nodePtr->value < num)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // put newNode between previodNode and nodePtr
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }

    // fucnction deletes a node
    void deleteNode(int num)
    {
        ListNode *nodePtr;
        ListNode *previousNode;

        // list is empty, do nothing
        if (!head)
            return;

        if (head->value == num)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        else
        {
            nodePtr = head;
            // skip nodes that dont match num
            while (nodePtr != nullptr && nodePtr->value != num)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // nodePtr not null, delete node
            if (nodePtr)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }

    // display contents in the list 
    void displayList() const
    {
        ListNode *nodePtr = head;

        while (nodePtr)
        {
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

private:
    // destructor helper fucntion
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

// LinkesList class
int main()
{
    LinkedList list;
    cout << "Appending values 10, 20, 40...\n";
    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(40);
    list.displayList();

    cout << "\nPlacing 30 into the list...\n";
    list.insertNode(30);
    list.displayList();

    cout << "\nDeleting 20 from the list...\n";
    list.deleteNode(20);
    list.displayList();

    cout << "\nEnd of program.\n";
    return 0;
}