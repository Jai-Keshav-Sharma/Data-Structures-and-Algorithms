//LEETCODE PROBLEM - 78

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Generates all possible subsets of a given array.
 * 
 * This function uses recursion to generate all possible subsets of the input array.
 * It considers each element of the array and either includes it in the current subset
 * or excludes it, thus generating all possible combinations.
 * 
 * @param arr The input array for which subsets are to be generated.
 * @param output The current subset being constructed.
 * @param index The current index in the input array being considered.
 * @param ans A reference to the vector of vectors where all generated subsets will be stored.
 */
void subsets(vector<int> arr, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    subsets(arr, output, index + 1, ans);

    // include
    int element = arr[index];
    output.push_back(element);
    subsets(arr, output, index + 1, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int n = nums.size();

    vector<vector<int>> ans;
    vector<int> output;

    subsets(nums, output, 0, ans);
    for (const vector<int> &each : ans)
    {
        cout << "{ ";
        for (int num : each)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}