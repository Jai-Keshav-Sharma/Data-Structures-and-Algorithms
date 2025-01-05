#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the next smaller element for each element in the given array.
 *
 * This function takes an array and its size as input and returns a vector
 * containing the next smaller element for each element in the array. If there
 * is no smaller element, it returns -1 for that position.
 *
 * @param arr The input array of integers.
 * @param n The size of the input array.
 * @return A vector containing the next smaller element for each element in the input array.
 */
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);

    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (st.top() >= curr && !st.empty())
            st.pop();

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}