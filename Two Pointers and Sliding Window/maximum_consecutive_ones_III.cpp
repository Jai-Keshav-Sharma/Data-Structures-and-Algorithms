// Leetcode 1004. Max Consecutive Ones III



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Finds the maximum number of consecutive 1s in the array if you can flip at most k 0s.
     * 
     * This function uses the sliding window technique to determine the longest subarray 
     * that contains at most k 0s. It maintains a window with two pointers, left (l) and 
     * right (r), and expands the window by moving the right pointer. If the number of 0s 
     * in the current window exceeds k, it shrinks the window by moving the left pointer.
     * 
     * @param nums A vector of integers containing only 0s and 1s.
     * @param k An integer representing the maximum number of 0s that can be flipped to 1s.
     * @return int The length of the longest subarray with at most k 0s.
     */
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int maxlen = 0;
        int len = 0;
        int zeros = 0;

        while (r < n)
        {
            if (nums[r] == 0)
            {
                zeros++;
            }

            if (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            if (zeros <= k)
            {
                len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};