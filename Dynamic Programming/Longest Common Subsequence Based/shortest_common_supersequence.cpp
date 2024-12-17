// LeetCode 1092. Shortest Common Supersequence

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the shortest common supersequence of two strings.
 * 
 * This function takes two strings as input and returns their shortest common supersequence.
 * The shortest common supersequence of two strings is the shortest string that has both 
 * input strings as subsequences.
 * 
 * @param str1 The first input string.
 * @param str2 The second input string.
 * @return A string representing the shortest common supersequence of str1 and str2.
 * 
 * The function uses dynamic programming to find the length of the longest common subsequence (LCS)
 * of the two input strings. It then constructs the shortest common supersequence by including 
 * characters from both strings, ensuring that the LCS is preserved.
 * 
 * Example:
 * @code
 * string str1 = "abc";
 * string str2 = "ac";
 * string result = shortestCommonSupersequence(str1, str2);
 * // result will be "abc"
 * @endcode
 */
string shortestCommonSupersequence(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];

            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    int i = n;
    int j = m;
    string lcs;

    // modified lcs finding logic to get the supersequence
    while (i > 0 and j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if (t[i - 1][j] > t[i][j - 1])
        {
            // including this element also as it contributes to the
            // supersequence
            lcs.push_back(str1[i - 1]);
            i--;
        }
        else
        {
            // including this element also as it contributes to the
            // supersequence
            lcs.push_back(str2[j - 1]);
            j--;
        }
    }

    // filling any leftover elements in str1
    while (i > 0)
    {
        lcs.push_back(str1[i - 1]);
        i--;
    }

    // filling any leftover elements in str2
    while (j > 0)
    {
        lcs.push_back(str2[j - 1]);
        j--;
    }

    reverse(lcs.begin(), lcs.end());

    return lcs;
}