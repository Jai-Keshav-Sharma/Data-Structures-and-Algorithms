#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the Longest Common Subsequence (LCS) between two strings.
 *
 * This function computes the LCS of two input strings using dynamic programming.
 * It constructs a 2D table to store the lengths of the longest common subsequence
 * at each subproblem and then backtracks to find the actual LCS string.
 *
 * @param n Length of the first string.
 * @param m Length of the second string.
 * @param s1 Reference to the first string.
 * @param s2 Reference to the second string.
 * @return The longest common subsequence as a string.
 */
string findLCS(int n, int m, string &s1, string &s2)
{
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

    int i = n;
    int j = m;
    string res;

    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }

        else if (t[i - 1][j] > t[i][j - 1])
            i--;

        else
            j--;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string s1 = "abac";
    string s2 = "cab";

    int n = s1.length();
    int m = s2.length();

    cout << "Longest Common Subsequence: " << findLCS(n, m, s1, s2) << endl;

    return 0;
}