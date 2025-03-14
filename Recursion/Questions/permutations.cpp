// LeetCode 46. Permutations

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Generates all permutations of the given vector of integers.
     *
     * This function uses recursion and backtracking to generate all possible
     * permutations of the input vector `nums`. The permutations are stored
     * in the `ans` vector of vectors.
     *
     * @param nums A reference to the vector of integers for which permutations are to be generated.
     * @param idx The current index in the vector from which permutations are being generated.
     * @param ans A reference to the vector of vectors where all generated permutations will be stored.
     * @param n The size of the input vector `nums`.
     *
     * @note The function modifies the `nums` vector during the process but restores it
     * to its original state before returning (backtracking).
     */
    void solve(vector<int> &nums, int idx, vector<vector<int>> &ans, int n)
    {
        if (idx >= n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            swap(nums[i], nums[idx]);
            solve(nums, idx + 1, ans, n);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();

        solve(nums, 0, ans, n);
        return ans;
    }
};