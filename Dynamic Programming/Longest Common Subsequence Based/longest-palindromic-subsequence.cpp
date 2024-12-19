// LeetCode 516. Longest Palindromic Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Computes the length of the longest palindromic subsequence in a given string.
     * 
     * This function takes a string and calculates the length of its longest palindromic subsequence (LPS).
     * It does this by finding the longest common subsequence (LCS) between the given string and its reverse.
     * 
     * @param s The input string for which the longest palindromic subsequence length is to be found.
     * @return int The length of the longest palindromic subsequence in the input string.
     */
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        // taking another string as the reverse of given string S
        string s2 = s;

        reverse(s2.begin(), s2.end());

        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

        // calculating length of their LCS which is also the length of their LPS
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == s2[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        return t[n][n];
    }
};
