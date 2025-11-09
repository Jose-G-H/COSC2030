#ifndef DYNQUE_H
#define DYNQUE_H

#include<iostream>
#include <cstdlib>
using namespace std;

// Dynqueue class template 

template <class T>
class Dynque
{
    private:
        struct QueueNode
        {
            T value;
            QueueNode *next;
        };

        QueueNode *front;
        QueueNode *rear;
        int numItems;
    public:
        Dynque();
        ~Dynque();
        void enqueue(T);
        void dequeue(T &);
        bool isEmpty();
        bool isFull();
        void clear();
};

//***********************************
// Constructor                      *
//***********************************

template <class T>
Dynque<T>::Dynque()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

//***********************************
// Destructor                      *
//***********************************
template <class T>
Dynque<T>::~Dynque()
{
    clear();
}

//***********************************
// enqueue func                     *
// adds a value to rear of queue    *
//***********************************
template <class T>
void Dynque<T>::enqueue(T item)
{
    QueueNode *newNode = new QueueNode;
    newNode->value = item;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

//***********************************
// dequeue func                     *
// Removes a value from front       *
//***********************************
template <class T>
void Dynque<T>::dequeue(T &item)
{
    QueueNode *temp;

    if (isEmpty())
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
    else
    {
        item = front->value;
        temp = front;
        front = front->next;
        delete temp;
        numItems--;
    }
}

//***********************************
// isEmpty func                     *
// true if queue is empty           *
//***********************************
template <class T>
bool Dynque<T>::isEmpty()
{
    return numItems== 0;
}

//***********************************
// isFull func                      *
// dynamic queue, always false      *
//***********************************
template <class T>
bool Dynque<T>::isFull()
{
    return false;
}

//***********************************
// Clear func                       *
// removes all elements             *
//***********************************
template <class T>
void Dynque<T>::clear()
{
    T value;
    while (!isEmpty())
    dequeue(value);
}

#endif