#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the length of the longest common substring between two strings.
 * 
 * This function uses dynamic programming to find the length of the longest common substring
 * between two input strings. It constructs a 2D table where the entry at (i, j) represents
 * the length of the longest common substring ending at str1[i-1] and str2[j-1].
 * 
 * @param str1 Reference to the first input string.
 * @param str2 Reference to the second input string.
 * @return int The length of the longest common substring.
 */
int lcs(string &str1, string &str2)
{
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> t(n + 1, vector<int>(m + 1));

    // initialisation
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int j = 1; j < m + 1; j++)
        t[0][j] = 0;

    int maxLength = 0;

    // filling table
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                maxLength = max(maxLength, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return maxLength;
}