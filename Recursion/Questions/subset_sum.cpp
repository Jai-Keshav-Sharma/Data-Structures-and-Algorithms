#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively calculates all possible subset sums of an array.
 * 
 * This function explores all subsets of the given array by either including 
 * or excluding the current element at index `i`. The sum of each subset is 
 * stored in the `ans` vector.
 * 
 * @param arr The input array of integers.
 * @param i The current index in the array being processed.
 * @param sum The cumulative sum of the current subset.
 * @param ans A reference to a vector where all subset sums will be stored.
 * @param n The size of the input array.
 * 
 * @note This function uses recursion to explore all subsets. The base case 
 *       is when the index `i` is greater than or equal to `n`, at which point 
 *       the current subset sum is added to the `ans` vector.
 */
void solve(vector<int> &arr, int i, int sum, vector<int> &ans, int n)
{
    if (i >= n)
    {
        ans.push_back(sum);
        return;
    }

    // picking up
    solve(arr, i + 1, sum + arr[i], ans, n);

    // not picking up
    solve(arr, i + 1, sum, ans, n);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int sum = 0;
    int n = num.size();

    solve(num, 0, sum, ans, n);
    sort(ans.begin(), ans.end());

    return ans;
}