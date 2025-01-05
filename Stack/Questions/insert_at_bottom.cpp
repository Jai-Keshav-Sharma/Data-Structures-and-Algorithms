
#include <stack>
using namespace std;

/**
 * @brief Inserts an element at the bottom of a stack.
 *
 * This function takes a stack and an integer value as input and inserts the integer
 * at the bottom of the stack using recursion. The function first checks if the stack
 * is empty. If it is, it pushes the integer onto the stack. Otherwise, it pops the
 * top element, makes a recursive call to process the rest of the stack, and then
 * pushes the popped element back onto the stack.
 *
 * @param myStack The stack in which the element is to be inserted.
 * @param x The integer value to be inserted at the bottom of the stack.
 */
void solve(stack<int> &myStack, int x)
{
    // Base case: when count reaches the size of the stack, push `x` at the bottom
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    // Store the top element and pop it
    int num = myStack.top();
    myStack.pop();

    // Recursive call to process the rest of the stack
    solve(myStack, x);

    // Push the stored element back after the recursive call
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    int cnt = 0; // Start with count 0
    solve(myStack, x);

    return myStack;
}
