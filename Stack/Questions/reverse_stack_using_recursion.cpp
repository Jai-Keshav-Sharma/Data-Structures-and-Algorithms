

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    // Store the top element and pop it
    int num = stack.top();
    stack.pop();

    // Recursive call to process the rest of the stack
    insertAtBottom(stack, x);

    // Push the stored element back after the recursive call
    stack.push(num);
}

void solve(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    // RECURSIVE CALL
    solve(stack);

    insertAtBottom(stack, num);
}

void reverseStack(stack<int> &stack)
{
    if (stack.size() == 1)
        return;

    solve(stack);
}