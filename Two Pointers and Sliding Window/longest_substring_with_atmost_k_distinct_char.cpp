// LeetCode 340. Longest Substring with At Most K Distinct Characters

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the length of the longest substring with at most k distinct characters.
 * 
 * This function uses the sliding window technique along with a hash map to keep track
 * of the frequency of characters in the current window. It expands the window by moving
 * the right pointer and contracts it by moving the left pointer when the number of distinct
 * characters exceeds k.
 * 
 * @param k The maximum number of distinct characters allowed in the substring.
 * @param str The input string in which to find the longest substring.
 * @return int The length of the longest substring with at most k distinct characters.
 */
int kDistinctChars(int k, string &str)
{
    int n = str.length();
    int l = 0;
    int r = 0;
    int maxlen = 0;

    unordered_map<char, int> mpp;

    while (r < n)
    {
        mpp[str[r]]++;

        if (mpp.size() > k)
        {

            mpp[str[l]]--;

            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);

            l++;
        }

        if (mpp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
