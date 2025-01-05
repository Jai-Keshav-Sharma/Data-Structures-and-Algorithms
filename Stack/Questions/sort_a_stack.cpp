#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Inserts an element into a sorted stack such that the stack remains sorted.
 *
 * This function takes a reference to a stack and an integer value. It inserts the integer
 * into the stack in such a way that the stack remains sorted in ascending order.
 *
 * @param stack Reference to the stack of integers.
 * @param x The integer value to be inserted into the stack.
 */
void sortPush(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    int num = stack.top();
    if (num > x)
    {
        stack.pop();
        sortPush(stack, x);
        stack.push(num);
    }
    else
        stack.push(x);
}

/**
 * @brief Recursively sorts a stack.
 * 
 * This function removes the top element of the stack, recursively sorts the 
 * remaining stack, and then inserts the removed element back into the sorted stack 
 * in its correct position.
 * 
 * @param stack Reference to the stack of integers to be sorted.
 */
void solve(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    // RECURSIVE CALL
    solve(stack);

    // insert num into correct position in sorted stack
    sortPush(stack, num);
}

void sortStack(stack<int> &stack)
{
    if (stack.size() == 1)
        return;

    solve(stack);
}