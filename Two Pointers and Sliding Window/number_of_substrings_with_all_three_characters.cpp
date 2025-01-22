// LeetCode 1358. Number of Substrings Containing All Three Characters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Counts the number of substrings containing all three characters 'a', 'b', and 'c'.
     *
     * This function takes a string as input and returns the number of substrings that contain
     * at least one occurrence of each of the characters 'a', 'b', and 'c'. It uses a sliding
     * window approach with two pointers to efficiently find and count these substrings.
     *
     * @param s The input string consisting of characters.
     * @return The number of substrings containing all three characters 'a', 'b', and 'c'.
     */
    int numberOfSubstrings(string s) {
        int n = s.length();

        int l = 0;
        int r = 0;
        int count = 0;

        unordered_map<char, int> mpp;

        // consider this test case: "abcabc"
        // in this, first valid string to be found is "abc"
        // now, one thing to observe here is that the strings "abc", "abca",
        // "abcab", "abcabc" will also be valid number of these valid strings
        // after a valid string is found is (n - r)

        while (r < n) {
            mpp[s[r]]++;

            while (mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1) {
                mpp[s[l]]--;
                l++;

                count = count + (n - r);
            }
            r++;
        }
        return count;
    }
};