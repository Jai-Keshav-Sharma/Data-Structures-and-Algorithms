// LeetCode 3. Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Finds the length of the longest substring without repeating characters.
     * 
     * This function uses the sliding window technique along with a hash map to keep track of the last seen positions of characters.
     * It iterates through the string, adjusting the window size to ensure no characters are repeated within the window.
     * 
     * @param s The input string to be processed.
     * @return int The length of the longest substring without repeating characters.
     */
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        vector<int> hash(256, -1);

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                if (hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxlen = max(len, maxlen);

            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};