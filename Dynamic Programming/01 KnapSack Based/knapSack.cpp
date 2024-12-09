#include <bits/stdc++.h>
using namespace std;



/**
 * @brief Solves the 0/1 Knapsack problem using dynamic programming.
 * 
 * This function calculates the maximum value that can be put in a knapsack
 * of capacity `w` given `n` items with specific weights and values.
 * 
 * @param wt An array of integers representing the weights of the items.
 * @param val An array of integers representing the values of the items.
 * @param w An integer representing the maximum capacity of the knapsack.
 * @param n An integer representing the number of items.
 * @return The maximum value that can be achieved with the given constraints.
 */
int knapSack(int wt[], int val[], int w, int n)
{
    // table initialization
    vector<vector<int>> t(n + 1, vector<int>(w + 1, 0));

    //filling table
    for(int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

int main()
{

    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;
    int n = 4;
    cout << knapSack(wt, val, w, n);

    return 0;
}