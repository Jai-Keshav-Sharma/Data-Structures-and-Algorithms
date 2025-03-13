// LeetCode 40. Combination Sum II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Recursive function to find all unique combinations in candidates where the candidate numbers sum to target.
     * 
     * @param candidates A vector of integers representing the candidate numbers.
     * @param idx The current index in the candidates vector.
     * @param target The remaining target sum to be achieved.
     * @param ds A vector to store the current combination of numbers.
     * @param ans A vector of vectors to store all the unique combinations that sum to the target.
     * @param n The size of the candidates vector.
     * 
     * This function avoids duplicate combinations by skipping over consecutive duplicate numbers.
     * It also stops further recursion if the current candidate number exceeds the remaining target sum.
     */
    void solve(vector<int> &candidates, int idx, int target, vector<int> &ds,
               vector<vector<int>> &ans, int n)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ds.push_back(candidates[i]);
            solve(candidates, i + 1, target - candidates[i], ds, ans, n);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> ds;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, ds, ans, candidates.size());
        return ans;
    }
};