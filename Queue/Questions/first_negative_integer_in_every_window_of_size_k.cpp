#include <bits/stdc++.h>
using namespace std;

// ------------------------- BRUTE FORCE APPROACH ----------------
/**
 * @brief Finds the first negative integer in every window of size k in the given array.
 * 
 * This function takes a vector of integers and an integer k, and returns a vector
 * containing the first negative integer in every window of size k. If a window does not
 * contain any negative integers, the function adds 0 to the result for that window.
 * 
 * @param arr A reference to a vector of integers.
 * @param k The size of the window.
 * @return A vector of integers containing the first negative integer in each window of size k.
 */
vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i <= n - k; i++)
    {
        bool NegFound = false;
        for (int j = 0; j < k; j++)
        {
            if (arr[i + j] < 0)
            {
                res.push_back(arr[i + j]);
                NegFound = true;
                break;
            }
        }
        if (!NegFound)
        {
            res.push_back(0);
        }
    }
    return res;
}

// -------------------------OPTIMAL APPRAOCH-----------------------

vector<int> FirstNegativeInteger(vector<int> &arr, int k)
{
    int n = arr.size();
    int l = 0;
    int r = 0;

    vector<int> ans;
    queue<int> q;

    while (r < n)
    {
        if (arr[r] < 0)
        {
            q.push(arr[r]);
        }

        if ((r - l + 1) == k)
        {
            if (!q.empty())
            {
                ans.push_back(q.front());
            }
            else
            {
                ans.push_back(0);
            }

            if (arr[l] < 0)
            {
                q.pop();
            }
            l++;
        }
        r++;
    }
    return ans;
}
