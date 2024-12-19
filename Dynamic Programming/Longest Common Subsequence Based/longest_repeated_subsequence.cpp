#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the length of the longest repeating subsequence in a given string.
 * 
 * This function takes a reference to a string and calculates the length of the longest
 * subsequence that appears at least twice in the string. The subsequences must not overlap.
 * 
 * @param s A reference to the input string.
 * @return int The length of the longest repeating subsequence.
 */
int LongestRepeatingSubsequence(string &s)
{
    string s2 = s;
    int n = s.length();

    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == s2[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][n];
}