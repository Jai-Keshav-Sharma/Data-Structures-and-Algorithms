// LeetCode 90. Subsets II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Generates all unique subsets of a given array, including the empty subset.
     * 
     * This function uses recursion and backtracking to explore all possible subsets
     * of the input array `nums`. It ensures that duplicate subsets are not included
     * in the result by skipping over duplicate elements during the recursive calls.
     * 
     * @param nums The input array of integers, which may contain duplicates.
     *             It is assumed to be sorted in non-decreasing order before calling this function.
     * @param idx The current index in the array from which to consider elements for the subset.
     * @param ds A temporary data structure (vector) to store the current subset being constructed.
     * @param ans A reference to the vector of vectors where all unique subsets will be stored.
     * @param n The size of the input array `nums`.
     */
    void solve(vector<int> &nums, int idx, vector<int> &ds,
               vector<vector<int>> &ans, int n)
    {

        ans.push_back(ds);
        for (int i = idx; i < n; i++)
        {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            ds.push_back(nums[i]);
            solve(nums, i + 1, ds, ans, n);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        solve(nums, 0, ds, ans, n);
        return ans;
    }
};