#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds the number of ways to assign symbols to make the sum of elements equal to target.
     * 
     * This function uses dynamic programming to find the number of ways to assign '+' and '-' 
     * symbols to the elements of the given array such that their sum equals the given target.
     * 
     * @param nums A vector of integers representing the array of numbers.
     * @param target An integer representing the target sum.
     * @return int The number of ways to assign symbols to make the sum of elements equal to target.
     * 
     * The function first calculates the sum of all elements in the array. It then calculates the 
     * required subset sum (s1) using the formula (target + sum) / 2. If the sum of the array is 
     * less than the absolute value of the target or if (sum + target) is odd, it returns 0 as it 
     * is not possible to partition the array to achieve the target sum.
     * 
     * The function uses a 2D vector 't' to store the number of ways to achieve each subset sum 
     * for each prefix of the array. It initializes t[0][0] to 1, as there is one way to achieve 
     * a sum of 0 with an empty subset. It then iterates through the array and updates the vector 
     * based on whether the current element can be included in the subset or not.
     * 
     * Finally, it returns the value of t[n][s1], which represents the number of ways to achieve 
     * the target sum with all elements of the array.
     */
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        // calculating sum of array elements
        for (int i = 0; i < n; i++)
            sum += nums[i];

        int s1 = (target + sum) / 2;

        // edge case
        if ((sum < abs(target)) || ((sum + target) % 2 != 0))
            return 0;

        vector<vector<int>> t(n + 1, vector<int>(s1 + 1, 0));
        t[0][0] = 1;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < s1 + 1; j++) {
                if (nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return t[n][s1];
    }
};