// LeetCode 992. Subarrays with K Different Integers

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Counts the number of subarrays with at most k different integers.
     * 
     * This function uses the sliding window technique to find the number of subarrays
     * in the given vector `nums` that contain at most `k` different integers.
     * 
     * @param nums A vector of integers representing the input array.
     * @param k An integer representing the maximum number of different integers allowed in a subarray.
     * @return int The number of subarrays with at most `k` different integers.
     */
    int solve(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;

        int n = nums.size();
        int r = 0;
        int l = 0;
        int cnt = 0;
        int goal = k;

        unordered_map<int, int> mpp;

        while (r < n)
        {
            mpp[nums[r]]++;

            while (mpp.size() > goal)
            {
                mpp[nums[l]]--;

                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);

                l++;
            }

            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};