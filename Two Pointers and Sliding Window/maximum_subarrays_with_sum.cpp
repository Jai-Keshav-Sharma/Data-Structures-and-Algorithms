// LeetCode 930. Binary Subarrays With Sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // to calculate the number of subaarrays having sum <= goal
    /**
     * @brief Calculates the number of subarrays with a sum less than or equal to the given goal.
     * 
     * This function uses the sliding window technique to find the number of subarrays
     * whose sum is less than or equal to the specified goal. It iterates through the
     * array while maintaining a window of elements that satisfy the condition.
     * 
     * @param nums A vector of integers representing the input array.
     * @param goal An integer representing the target sum for the subarrays.
     * @return An integer representing the count of subarrays with a sum less than or equal to the goal.
     */
    int solve(vector<int> &nums, int goal)
    {

        if (goal < 0)
            return 0;

        int n = nums.size();

        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;

        while (r < n)
        {
            sum = sum + nums[r];

            while (sum > goal)
            {
                sum = sum - nums[l];
                l++;
            }

            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    /**
     * @brief Finds the number of subarrays with a given sum.
     * 
     * This function calculates the number of subarrays in the input vector `nums`
     * that sum up to the specified `goal`. It does this by first finding the number
     * of subarrays with sums less than or equal to `goal`, and then subtracting the
     * number of subarrays with sums less than or equal to `goal - 1`. The difference
     * gives the number of subarrays with the exact sum equal to `goal`.
     * 
     * @param nums A reference to a vector of integers representing the input array.
     * @param goal An integer representing the target sum for the subarrays.
     * @return An integer representing the number of subarrays with the exact sum equal to `goal`.
     */
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        // approach: first we r finding the number of subarrays that have sum <=
        // goal and then subtract the number of subaarays that have sum <= goal
        // - 1 then we get the number of subaarays with the desired sum

        return solve(nums, goal) - solve(nums, goal - 1);
    }
};