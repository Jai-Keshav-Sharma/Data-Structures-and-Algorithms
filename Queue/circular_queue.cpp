#include <bits/stdc++.h>
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the
    // stack, and false otherwise.
    bool enqueue(int value)
    {
        // Write your code here.
        if (rear == size - 1 && front == 0)
            return false;
        if (rear == front - 1)
            return false;
        if (front == -1)
        {
            front++;
            rear++;
            arr[rear] = value;
            return true;
        }
        if (rear == size - 1 && front != 0)
        {
            rear++;
            rear = rear % size;
            arr[rear] = value;
            return true;
        }
        rear++;
        rear = rear % size;
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int dequeue()
    {
        // Write your code here.
        if (front == -1)
            return -1;

        int popped = arr[front];

        if (rear == front)
        {
            front = -1;
            rear = -1;
            return popped;
        }

        if (front == size - 1)
        {
            front++;
            front = front % size;
            return popped;
        }
        front++;
        return popped;
    }
};