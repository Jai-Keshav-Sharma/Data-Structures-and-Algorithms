//LeetCode 1312. Minimum Insertion Steps to Make a String Palindrome

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Calculates the minimum number of insertions required to make a given string a palindrome.
 * 
 * This function uses dynamic programming to find the longest common subsequence (LCS) between the 
 * given string and its reverse. The minimum number of insertions required to make the string a 
 * palindrome is then derived from the length of the LCS.
 * 
 * @param str Reference to the input string.
 * @return int The minimum number of insertions required to make the input string a palindrome.
 */
int minimumInsertions(string &str)
{
    string s2 = str;
    reverse(s2.begin(), s2.end());

    int n = str.length();

    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    int insertions = n - t[n][n];
    return insertions;
}
