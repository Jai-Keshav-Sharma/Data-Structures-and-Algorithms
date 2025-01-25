#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{

    int l = 0;
    int r = 0;

    vector<int> ans;
    queue<int> q;

    while (r < n)
    {
        if (arr[r] < 0)
            q.push(arr[r]);

        if (r - l + 1 == k)
        {
            if (!q.empty())
                ans.push_back(q.front());
            else
                ans.push_back(0);

            if (arr[l] < 0)
                q.pop();

            l++;
        }
        r++;
    }
    return ans;
}
