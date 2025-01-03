#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    // operations
    Stack() {};

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
            cout << "Stack Overflow !" << endl;
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "stack is empty !" << endl;
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
            cout << "stack is empty !" << endl;
        return -1;
    }

    bool empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st(5);

    st.push(2);
    st.push(1);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6); // overflow

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    if (st.empty())
        cout << "is empty" << endl;
    else
        cout << "is not empty" << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    if (st.empty())
        cout << "is empty" << endl;
    else
        cout << "is not empty" << endl;

    cout << st.peek() << endl;

    return 0;
}