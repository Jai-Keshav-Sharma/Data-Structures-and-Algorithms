#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solves the coin change problem using dynamic programming.
 *
 * Given an integer `amount` and an array `coins` where `coins[i]` represents
 * the denomination of the `i`-th coin, this function computes the number of
 * combinations that make up that amount.
 *
 * @param amount The amount to make up.
 * @param coins A vector of integers where each element represents the
 *              denomination of a coin.
 * @return The number of combinations that make up the amount.
 */
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<vector<long long>> t(n + 1, vector<long long>(amount + 1, 0));

        for (int i = 0; i < n + 1; i++)
            t[i][0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    // Check for overflow before adding
                    if (t[i - 1][j] > LLONG_MAX - t[i][j - coins[i - 1]])
                        t[i][j] = LLONG_MAX; // Set to a large value to indicate overflow
                    else
                        t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
                }
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        return (t[n][amount] > INT_MAX) ? 0 : static_cast<int>(t[n][amount]);
    }
};