// LeetCode 424. Longest Repeating Character Replacement

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Finds the length of the longest substring containing the same letter 
     * that can be obtained by replacing at most k characters in the given string.
     * 
     * @param s The input string.
     * @param k The maximum number of characters that can be replaced.
     * @return int The length of the longest substring with the same letter after at most k replacements.
     */
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxf = 0;

        unordered_map<char, int> mpp;

        while (r < n)
        {
            mpp[s[r]]++;

            maxf = max(maxf, mpp[s[r]]);

            if ((r - l + 1 - maxf) > k)
            {
                while ((r - l + 1 - maxf) > k)
                {
                    mpp[s[l]]--;
                    l++;
                }
            }

            if ((r - l + 1 - maxf) <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};