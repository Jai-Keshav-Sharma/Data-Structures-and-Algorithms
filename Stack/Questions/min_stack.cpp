#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    stack<int> s;
    int mini = INT_MAX;

public:
    /**
     * @brief Pushes an element onto the stack and updates the minimum element.
     * 
     * This function pushes the given data onto the stack. If the stack is empty,
     * it initializes the minimum element with the given data. If the stack is not
     * empty and the given data is less than the current minimum element, it pushes
     * a modified value onto the stack and updates the minimum element. Otherwise,
     * it simply pushes the given data onto the stack.
     * 
     * @param data The integer value to be pushed onto the stack.
     */
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    void pop()
    {
        if (s.empty())
            return;

        int curr = s.top();
        s.pop();

        if (curr > mini)
        {
            return;
        }
        else
        {
            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
            return;
            ;
        }
    }

    int top()
    {
        if (s.empty())
            return -1;
        int curr = s.top();

        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int getMin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};