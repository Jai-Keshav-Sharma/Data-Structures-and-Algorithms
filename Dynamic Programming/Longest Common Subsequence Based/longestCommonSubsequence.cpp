//LeetCode 1143. Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Computes the length of the longest common subsequence between two strings.
     * 
     * This function uses dynamic programming to find the length of the longest common subsequence
     * (LCS) between two input strings, text1 and text2. The LCS is the longest sequence that can 
     * be derived from both strings by deleting some or no characters without changing the order 
     * of the remaining characters.
     * 
     * @param text1 The first input string.
     * @param text2 The second input string.
     * @return int The length of the longest common subsequence between text1 and text2.
     */
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();

        // table declaration
        vector<vector<int>> t(n + 1, vector<int>(m + 1));

        // initialisation
        for (int i = 0; i < n + 1; i++)
            t[i][0] = 0;
        for (int j = 1; j < m + 1; j++)
            t[0][j] = 0;

        // filling table
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        return t[n][m];
    }
};