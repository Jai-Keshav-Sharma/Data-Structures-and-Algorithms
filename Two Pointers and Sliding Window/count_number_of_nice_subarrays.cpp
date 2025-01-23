// LeetCode 1248. Count Number of Nice Subarrays

#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    /**
     * @brief Counts the number of subarrays with at most k odd numbers.
     * 
     * This function uses the sliding window technique to count the number of subarrays
     * in the given vector `nums` that contain at most `k` odd numbers.
     * 
     * @param nums A vector of integers.
     * @param k The maximum number of odd numbers allowed in the subarrays.
     * @return int The count of subarrays with at most `k` odd numbers.
     */
    int solve(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int n = nums.size();
        int r = 0;
        int l = 0;
        int cnt = 0;
        int goal = 0;

        while (r < n) {
            if (nums[r] & 1)
                goal = goal + 1;

            while (goal > k && l <= r) {
                if (nums[l] & 1)
                    goal--;
                l++;
            }

            cnt = cnt + (r - l + 1);

            r++;
        }
        return cnt;
    }

public:
    /**
     * @brief Counts the number of "nice" subarrays in the given vector.
     * 
     * A "nice" subarray is defined as a subarray that contains exactly k odd numbers.
     * 
     * @param nums A vector of integers.
     * @param k The number of odd numbers that a subarray must contain to be considered "nice".
     * @return int The number of "nice" subarrays in the given vector.
     */
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};