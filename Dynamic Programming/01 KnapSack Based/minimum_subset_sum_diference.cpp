/*
    You are given an array 'arr' containing 'n' non-negative integers.
    Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
    You just need to find the minimum absolute difference considering any valid division of the array elements.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the minimum difference between the sums of two subsets of a given vector of integers.
 *
 * This function takes a vector of integers and partitions it into two subsets such that the absolute difference
 * between the sums of the subsets is minimized. It uses dynamic programming to solve the problem efficiently.
 *
 * @param nums A vector of integers representing the input set.
 * @return An integer representing the minimum difference between the sums of the two subsets.
 *
 * @note The function handles empty input vectors by returning 0.
 * @note The function assumes that the input vector may contain negative numbers, but the handling of negative inputs is commented out.
 */
int minSumDiff(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0;

    int sum = 0;

    // handling -ve inputs
    //  int minElement = *min_element(nums.begin(), nums.end());
    //  int offset = abs(minElement);

    for (int i = 0; i < n; i++)
    {
        // nums[i] += offset;
        sum += nums[i];
    }

    // table initialisation
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        t[0][j] = false;
    } // table initialisation

    // table filling
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    } // table filling

    // getting possible sum values
    vector<int> res;
    for (int i = 0; i < sum + 1; i++)
    {
        if (t[n][i] == true)
            res.push_back(i);
    }

    // checking foe min sum difference
    int mini = INT_MAX;
    for (int i = 0; i < res.size(); i++)
    {
        int diff = abs(sum - 2 * res[i]);
        mini = min(diff, mini);
    }

    return mini;
}

int main()
{

    vector<int> nums = {91, 14, 16, 82, 32, 2, 38, 94};
    cout << minSumDiff(nums);

    return 0;
}