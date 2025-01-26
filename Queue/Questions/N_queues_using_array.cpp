#include <bits/stdc++.h>
using namespace std;

class NQueue
{
public:
    // Initialize your data structure.

    int n;
    int s;
    int *front;
    int *rear;
    int *next;
    int freespot;
    int *arr;

    /**
     * @brief Constructor to initialize NQueue with given number of queues and size.
     * 
     * @param n Number of elements in the array.
     * @param s Number of queues.
     * 
     * This constructor initializes the following:
     * - `front` and `rear` arrays of size `s` to keep track of the front and rear indices of each queue.
     * - `next` array of size `n` to manage the next free spot in the array.
     * - `freespot` to keep track of the first free index in the array.
     * - `arr` array of size `n` to store the elements of the queues.
     * 
     * The `front` and `rear` arrays are initialized to -1 indicating that all queues are initially empty.
     * The `next` array is initialized such that each element points to the next index, and the last element points to -1.
     */
    NQueue(int n, int s)
    {
        this->n = n;
        this->s = s;

        front = new int[s];
        rear = new int[s];

        for (int i = 0; i < s; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freespot = 0;
        arr = new int[n];
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        // overflow
        if (freespot == -1)
            return false;

        int index = freespot;
        freespot = next[index];

        if (front[m - 1] == -1)
        {
            front[m - 1] = index;
        }
        else
        {
            next[rear[m - 1]] = index;
        }

        // updating next
        next[index] = -1;

        // updating rear
        rear[m - 1] = index;

        // pushing value
        arr[index] = x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {
        // underflow
        if (front[m - 1] == -1)
            return -1;

        // finding index to pop
        int index = front[m - 1];

        // updating front
        front[m - 1] = next[index];

        // updating freeslot
        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};