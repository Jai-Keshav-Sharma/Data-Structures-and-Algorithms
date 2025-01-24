// LeetCode 76. Minimum Window Substring

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        // If the length of string s is less than string t, it's impossible to find a window
        if (n < m)
            return "";
        if (n == 0 || m == 0)
            return "";

        // Initialize pointers for the sliding window
        int r = 0;            // Right pointer
        int l = 0;            // Left pointer
        int minlen = INT_MAX; // Variable to store the minimum length of the window
        int stInd = -1;       // Variable to store the starting index of the minimum window
        int cnt = 0;          // Variable to count the number of characters matched

        // Create a frequency map for characters in string t
        vector<int> mpp(256, 0);
        for (int i = 0; i < m; i++)
            mpp[t[i]]++;

        // Start sliding the window
        while (r < n)
        {
            // If the current character in s is part of t, increment the count
            if (mpp[s[r]] > 0)
                cnt++;

            // Decrement the frequency of the current character in the map
            mpp[s[r]]--;

            // If all characters are matched, try to shrink the window from the left
            while (cnt == m)
            {
                // Update the minimum length and starting index if a smaller window is found
                if (r - l + 1 < minlen)
                {
                    minlen = r - l + 1;
                    stInd = l;
                }

                // Increment the frequency of the character at the left pointer in the map
                mpp[s[l]]++;

                // If the character at the left pointer is part of t, decrement the count
                if (mpp[s[l]] > 0)
                    cnt--;

                // Move the left pointer to the right
                l++;
            }

            // Move the right pointer to the right
            r++;
        }

        // If no valid window is found, return an empty string
        if (stInd == -1)
            return "";

        // Return the minimum window substring
        return s.substr(stInd, minlen);
    }
};