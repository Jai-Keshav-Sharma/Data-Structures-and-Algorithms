#include <bits/stdc++.h>
class Queue
{
    int *arr;
    int size;
    int frontInd;
    int rear;

public:
    Queue()
    {
        // Implement the Constructor
        size = 5001;
        arr = new int[size];
        frontInd = -1;
        rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (frontInd == -1)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
            return;
        if (frontInd == -1)
            frontInd++;
        rear++;
        arr[rear] = data;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (frontInd == -1)
            return -1;

        int popped = arr[frontInd];

        if (frontInd == rear)
        {
            frontInd = -1;
            rear = -1;
            return popped;
        }
        else
        {
            frontInd++;
            return popped;
        }
    }

    int front()
    {
        // Implement the front() function
        if (frontInd == -1)
            return -1;
        return arr[frontInd];
    }
};