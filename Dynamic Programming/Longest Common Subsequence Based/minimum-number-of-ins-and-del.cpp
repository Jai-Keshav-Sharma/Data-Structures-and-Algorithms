#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the minimum number of insertions and deletions required to transform string s1 into string s2.
 * 
 * This function uses dynamic programming to find the length of the longest common subsequence (LCS) between s1 and s2.
 * The number of deletions required is the difference between the length of s1 and the LCS length.
 * The number of insertions required is the difference between the length of s2 and the LCS length.
 * The sum of these deletions and insertions gives the minimum number of operations needed to transform s1 into s2.
 * 
 * @param s1 The first input string.
 * @param s2 The second input string.
 * @return int The minimum number of insertions and deletions required.
 */
int canYouMake(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    // approach:
    /*
        1. first make the LCS from string s1. This process will give u the number if deletions
        2. then make string s2 from the string s1(which u converted into LCS earlier).this will
            give u the number of inserions needed.
    */
    int lcsLen = t[n][m];

    int deletions = n - lcsLen;
    int insertions = m - lcsLen;

    return insertions + deletions;
}