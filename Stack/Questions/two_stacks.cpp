#include <bits/stdc++.h>
/**
 * @class TwoStack
 * @brief A class to implement two stacks in a single array.
 *
 * This class provides methods to push and pop elements from two separate stacks
 * that share the same underlying array. The two stacks grow towards each other
 * from opposite ends of the array.
 */
 
/**
 * @brief Constructor to initialize the TwoStack with a given size.
 * 
 * @param s The size of the array to be used for the two stacks.
 */
 
/**
 * @brief Push an element into stack 1.
 * 
 * @param num The element to be pushed into stack 1.
 * 
 * @note This method does nothing if there is no space left in the array for stack 1.
 */
 
/**
 * @brief Push an element into stack 2.
 * 
 * @param num The element to be pushed into stack 2.
 * 
 * @note This method does nothing if there is no space left in the array for stack 2.
 */
 
/**
 * @brief Pop an element from stack 1.
 * 
 * @return The element popped from stack 1, or -1 if stack 1 is empty.
 */
 
/**
 * @brief Pop an element from stack 2.
 * 
 * @return The element popped from stack 2, or -1 if stack 2 is empty.
 */
class TwoStack
{
    int size;
    int *arr;
    int top1;
    int top2;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        return -1;
    }
};
