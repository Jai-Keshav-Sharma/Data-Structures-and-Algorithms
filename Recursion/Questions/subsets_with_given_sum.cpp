#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively finds all subsets of the given array that sum up to a given value.
 * 
 * This function explores all possible subsets of the array `arr` and adds those subsets
 * whose elements sum up to `k` to the `ans` vector.
 * 
 * @param arr The input array of integers.
 * @param i The current index in the array `arr`.
 * @param output The current subset being constructed.
 * @param ans The vector of all subsets that sum up to `k`.
 * @param n The size of the input array `arr`.
 * @param sum The current sum of the elements in the `output` subset.
 * @param k The target sum for the subsets.
 */
void solve(vector<int> &arr, int i, vector<int> output, vector<vector<int>> &ans, int n, int sum, int k)
{
    if (sum == k)
    {
        ans.push_back(output);
        return;
    }
    if (i >= n || sum > k)
        return;

    // taking
    output.push_back(arr[i]);
    sum += arr[i];
    solve(arr, i + 1, output, ans, n, sum, k);

    // not taking
    output.pop_back();
    sum -= arr[i];
    solve(arr, i + 1, output, ans, n, sum, k);
}

vector<vector<int>> subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<int> output;
    vector<vector<int>> ans;
    int sum = 0;

    solve(arr, 0, output, ans, n, sum, k);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    vector<vector<int>> res = subsetSumToK(n, k, arr);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}