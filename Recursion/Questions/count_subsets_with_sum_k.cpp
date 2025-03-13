#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively counts the number of subsets in the given array that sum up to a specific value.
 * 
 * @param nums A reference to a vector of integers representing the array.
 * @param i The current index in the array.
 * @param sum The current sum of the subset being considered.
 * @param k The target sum for the subsets.
 * @param n The total number of elements in the array.
 * @return int The number of subsets that sum up to the target value k.
 */
int solve(vector<int> &nums, int i, int sum, int k, int n)
{

    if (i >= n)
    {
        if (sum == k)
            return 1;

        return 0;
    }

    // taking
    int l = solve(nums, i + 1, sum + nums[i], k, n);

    // not taking
    int r = solve(nums, i + 1, sum, k, n);

    return l + r;
}

int subarraySum(vector<int> &nums, int k)
{
    int sum = 0;
    int n = nums.size();

    return solve(nums, 0, sum, k, n);
}
