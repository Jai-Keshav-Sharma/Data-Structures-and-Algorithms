#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solves the rod cutting problem using dynamic programming.
 *
 * Given a rod of length `n` and an array `price` where `price[i]` represents
 * the price of a rod of length `i+1`, this function computes the maximum
 * obtainable value by cutting up the rod and selling the pieces.
 *
 * @param price A vector of integers where each element represents the price
 *              of a rod of a specific length.
 * @param n The length of the rod.
 * @return The maximum obtainable value by cutting up the rod and selling the pieces.
 */
int cutRod(vector<int> &price, int n)
{
    vector<int> length(n);
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }

    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][n];
}
