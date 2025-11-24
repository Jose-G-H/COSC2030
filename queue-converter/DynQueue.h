#ifndef DYNQUEUE_H
#define DYNQUEUE_H

#include <iostream>
using namespace std;

template <class T>
class DynQueue
{
private:
    struct QueueNode
    {
        T value;
        QueueNode *next;
    };

    QueueNode *front;
    QueueNode *rear;

public:
    DynQueue()
    { front = rear = nullptr; }

    ~DynQueue()
    { clear(); }

    void enqueue(T item)
    {
        QueueNode *newNode = new QueueNode;
        newNode->value = item;
        newNode->next = nullptr;

        if (!front)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(T &item)
    {
        QueueNode *temp;

        if(!front)
        {
            cout << "Queue is empty.\n";
            return;
        }

        item = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void clear()
    {
        T temp;
        while (!isEmpty())
            dequeue(temp);
    }
};

#endif