// LeetCode : 20. Valid Parentheses

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();

        if (n == 1)
            return false;

        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                // if the satck is empty and we ecounter closing parentheses,
                // then its not balanced
                if (st.empty())
                    return false;

                else if (s[i] == ']' && st.top() == '[')
                    st.pop();

                else if (s[i] == '}' && st.top() == '{')
                    st.pop();

                else if (s[i] == ')' && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};