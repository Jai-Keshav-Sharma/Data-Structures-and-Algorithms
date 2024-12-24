#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string &s, int i, int j, bool isTrue)
{

    // if empty
    if (i > j)
        return 0;

    // if single element
    if (i == j)
    {
        if (isTrue == true)
            return s[i] == 'T' ? 1 : 0;
        else
            return s[i] == 'F' ? 1 : 0;
    }

    string temp = to_string(i);
    temp.push_back(' ');

    temp.append(to_string(j));
    temp.push_back(' ');

    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
        return mp[temp];

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
            {
                ans = ans + lt * rt;
            }
            else
            {
                ans = ans + lt * rf + lf * rt + lf * rf;
            }
        }

        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans = ans + lt * rf + lf * rt + lt * rt;
            }
            else
            {
                ans = ans + lf * rf;
            }
        }

        else if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans = ans + lt * rf + lf * rt;
            }
            else
            {
                ans = ans + lt * rt + lf * rf;
            }
        }
    }
    return ans;
}

int countWays(int n, string s)
{
    return solve(s, 0, n - 1, true);
}

int main()
{
    string s = "T|T&F^T";
    cout << countWays(s.length(), s) << endl;
    return 0;
}