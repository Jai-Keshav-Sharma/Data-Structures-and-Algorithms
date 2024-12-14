//LEETCODE - 322. Coin Change

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Computes the minimum number of coins needed to make up a given amount.
     * 
     * This function uses a dynamic programming approach to solve the coin change problem.
     * It determines the minimum number of coins required to make up the specified amount
     * using the given denominations of coins.
     * 
     * @param coins A vector of integers representing the denominations of the coins.
     * @param amount An integer representing the total amount of money.
     * @return The minimum number of coins needed to make up the given amount. 
     *         If it is not possible to make up the amount with the given coins, returns -1.
     */

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> t(n + 1, vector<int>(amount + 1));

        // initialsing 1st row and 1st column
        for (int i = 0; i < n + 1; i++)
            t[i][0] = 0;
        for (int j = 0; j < amount + 1; j++)
            t[0][j] = INT_MAX - 1;

        // initialising 2nd row
        for (int j = 0; j < amount + 1; j++)
        {
            if (j % coins[0] == 0)
                t[1][j] = j / coins[0];
            else
                t[1][j] = INT_MAX - 1;
        }

        // filling table
        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        // checking if the sum is possible or not
        if (t[n][amount] == INT_MAX - 1)
            return -1;

        return t[n][amount];
    }
};