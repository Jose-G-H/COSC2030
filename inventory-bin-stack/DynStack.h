#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class DynStack
{
    private:
        struct StackNode
        {
            T value;
            StackNode *next;
        };

        StackNode *top;

    public:
        // constructor
        DynStack()
        {   top = nullptr; }

        // destructor
        ~DynStack()
        {   clear(); }

        // push, add to top of stack
        void push(T item)
        {
            StackNode *newNode = new StackNode;
            newNode->value = item;

            if (isEmpty())
                newNode->next = nullptr;
            else
                newNode->next = top;

            top = newNode;
        }

        // pop, remove from top of stack
        void pop(T &item)
        {
            StackNode *temp;

            if (isEmpty())
            {
                cout << "The stack is empty.\n";
                exit(1);
            }
            else
            {
                item = top->value;
                temp = top;
                top = top->next;
                delete temp;
            }
        }

        // check if stack is empty
        bool isEmpty() const
        {
            return top == nullptr;
        }

        // clear stack
        void clear()
        {
            T tempValue;
            while (!isEmpty())
                pop(tempValue);
        }

        // display the rest
        void displayAll()
        {
            StackNode *nodePtr = top;
            if (!nodePtr)
            {
                cout << "The stack is empty.\n";
                return;
            }

            cout << "\nParts remaining in inventory:\n";
            cout << "------------------------------\n";
            while (nodePtr)
            {
                nodePtr->value.display();
                cout << endl;
                nodePtr = nodePtr->next;
            }
        }
};

#endif