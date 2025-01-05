#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the minimum cost to make a given string of braces valid.
 *
 * This function calculates the minimum number of reversals required to make
 * a given string of braces valid. A string is considered valid if every
 * opening brace '{' has a corresponding closing brace '}'.
 *
 * @param str The input string consisting of '{' and '}' characters.
 * @return int The minimum cost (number of reversals) to make the string valid.
 *             Returns -1 if it's not possible to make the string valid.
 */
int findMinimumCost(string str)
{
    int n = str.length();

    // if length is odd, not possible to make string valid at any cost
    if (n & 1)
        return -1;

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    int a = 0; // count of opening braces
    int b = 0; // count of closing braces

    while (!st.empty())
    {
        if (st.top() == '{')
            a++;
        else
            b++;
        st.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}