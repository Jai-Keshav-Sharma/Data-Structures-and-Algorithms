#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Calculates the minimum number of deletions required to make a string a palindrome.
     *
     * This function takes a string as input and calculates the minimum number of deletions required
     * to make the string a palindrome. It does this by finding the length of the longest palindromic
     * subsequence (LPS) of the string.
     *
     * @param str The input string for which the minimum deletions are to be calculated.
     * @param n The length of the input string.
     * @return int The minimum number of deletions required to make the string a palindrome.
     */

    int minDeletions(string str, int n)
    {
        string s2 = str;

        reverse(s2.begin(), s2.end());

        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (str[i - 1] == s2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        return n - t[n][n];
    }
};