#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively removes the middle element from the stack.
 *
 * This function removes the middle element from the given stack by using a recursive approach.
 * It pops elements from the stack until it reaches the middle element, removes it, and then
 * pushes the previously popped elements back onto the stack.
 *
 * @param inputStack The stack from which the middle element is to be removed.
 * @param count The current count of elements processed, initially should be 0.
 * @param size The total size of the stack.
 */
void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    // storing elements that are being popped while going towards middle
    int num = inputStack.top();

    // removing those elements
    inputStack.pop();

    // RECURSIVE CALL
    solve(inputStack, count + 1, size);

    // putting elements back into stack
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}