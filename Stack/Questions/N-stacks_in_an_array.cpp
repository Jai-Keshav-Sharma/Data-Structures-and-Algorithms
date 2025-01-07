#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class NStack
/**
 * @file N-stacks_in_an_array.cpp
 * @brief Implementation of N stacks in a single array.
 * 
 * This file contains the implementation of a data structure that allows multiple stacks
 * to be managed within a single array. The data structure supports push and pop operations
 * for each stack.
 * 
 * The data structure uses three arrays:
 * - `arr`: The main array that stores the elements of all stacks.
 * - `top`: An array that stores the index of the top element of each stack.
 * - `next`: An array that helps in managing the next free spot in the main array.
 * 
 * The `NStack` class provides the following methods:
 * - `NStack(int N, int S)`: Constructor to initialize the data structure with N stacks and
 *   a total size of S.
 * - `bool push(int x, int m)`: Pushes an element `x` into the `m`-th stack. Returns true if
 *   the element is successfully pushed, and false if the stack is full.
 * - `int pop(int m)`: Pops the top element from the `m`-th stack. Returns the popped element,
 *   or -1 if the stack is empty.
 * 
 * The `next` array serves two purposes:
 * 1. If `arr[i]` is empty, `next[i]` stores the next free location after `arr[i]` is filled.
 * 2. If `arr[i]` is filled, `next[i]` stores the index which will be the top of that stack
 *    after popping `arr[i]`.
 * 
 * The `freespot` variable keeps track of the first free spot in the main array.
 */
{
    int *arr;
    int *top;
    int *next;
    int n;
    int s;
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialising top
        memset(top, -1, n * sizeof(int));

        // initialising next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // setting last element to -1 bcz after last index in the
                          // array there is no free space
        // the next[] array has two uses:
        //  1. if arr[i] is empty, then next[i] stores the next free location after
        //  arr[i] is filled
        //  2. if arr[i] is filled, it stores the index which will be the top of
        //  that stack m after popping arr[i].

        // initialising freespot, as first free spot is 0th index of the array
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
    // stack, and false otherwise.
    bool push(int x, int m)
    {
        // overflow condition
        if (freespot == -1)
            return false;

        // knowing where to insert
        int index = freespot;

        // inserting element
        arr[index] = x;

        // updating freespot
        freespot = next[index];

        // updating next
        next[index] = top[m - 1]; // this is a 0 based indexing, so 1st stack top is
                                  // stored at top[0];

        // updating top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty,
    // otherwise returns the popped element.
    int pop(int m)
    {
        // underflow condition
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];

        // updating top
        top[m - 1] = next[index];

        // updating next
        next[index] = freespot;

        // updating freespot
        freespot = index;

        return arr[index];
    }
};