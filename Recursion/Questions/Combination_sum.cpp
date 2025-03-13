// LeetCode 39. Combination Sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Recursive function to find all unique combinations in candidates where the candidate numbers sum to target.
     * 
     * @param candidates Vector of candidate numbers.
     * @param i Current index in the candidates vector.
     * @param target The remaining target sum to be achieved.
     * @param n Total number of candidates.
     * @param ds Current combination of numbers that sum up to the target.
     * @param ans Vector to store all the unique combinations that sum up to the target.
     */
    void solve(vector<int> &candidates, int i, int target, int n,
               vector<int> ds, vector<vector<int>> &ans)
    {
        if (i == n)
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        // picking up
        if (candidates[i] <= target)
        {
            ds.push_back(candidates[i]);
            solve(candidates, i, target - candidates[i], n, ds, ans);
            ds.pop_back();
        }

        // not picking
        solve(candidates, i + 1, target, n, ds, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> ds;
        vector<vector<int>> ans;

        solve(candidates, 0, target, candidates.size(), ds, ans);
        return ans;
    }
};