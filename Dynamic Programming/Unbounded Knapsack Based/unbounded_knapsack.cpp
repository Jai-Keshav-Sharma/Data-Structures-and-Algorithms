#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solves the Unbounded Knapsack problem.
 * 
 * This function calculates the maximum profit that can be obtained by putting items 
 * in a knapsack of capacity `w` where each item can be included multiple times.
 * 
 * @param profit A vector of integers representing the profit of each item.
 * @param weight A vector of integers representing the weight of each item.
 * @param n The number of items.
 * @param w The capacity of the knapsack.
 * @return The maximum profit that can be obtained with the given constraints.
 */
int unboundedKnapsack(vector<int> profit, vector<int> weight, int n, int w)
{
    vector<vector<int>> t(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (weight[i - 1] <= j)
                t[i][j] = max(profit[i - 1] + t[i][j - weight[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

int main()
{

    vector<int> val = {1, 1}, wt = {2, 1};
    int capacity = 3;
    cout << unboundedKnapsack(val, wt, 2, 3);

    return 0;
}