#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int size;
    int rear;
    int front;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~Deque() { delete[] arr; }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into
    // the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull())
            return false;

        if (front == -1)
        { // If deque is empty
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + size) % size; // Circular decrement
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into
    // the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull())
            return false;

        if (front == -1)
        { // If deque is empty
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size; // Circular increment
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is
    // empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
            return -1;

        int popped = arr[front];
        if (front == rear)
        { // If deque becomes empty
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size; // Circular increment
        }
        return popped;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is
    // empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
            return -1;

        int popped = arr[rear];
        if (front == rear)
        { // If deque becomes empty
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + size) % size; // Circular decrement
        }
        return popped;
    }

    // Returns the first element of the deque. If the deque is empty, it returns
    // -1.
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns
    // -1.
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty() { return front == -1; }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull() { return (front == (rear + 1) % size); }
};