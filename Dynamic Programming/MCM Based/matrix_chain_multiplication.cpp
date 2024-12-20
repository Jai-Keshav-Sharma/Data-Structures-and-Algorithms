#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;

/**
 * @brief Solves the Matrix Chain Multiplication problem using dynamic programming.
 * 
 * This function computes the minimum number of scalar multiplications needed to multiply
 * a chain of matrices. It uses memoization to store intermediate results and avoid redundant
 * calculations.
 * 
 * @param arr A reference to a vector of integers representing the dimensions of the matrices.
 * @param i The starting index of the subproblem (inclusive).
 * @param j The ending index of the subproblem (inclusive).
 * @return The minimum number of scalar multiplications needed to multiply the matrices from index i to j.
 */
int solve(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mini = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp_sol = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, temp_sol);
    }

    return t[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    t = vector<vector<int>>(101, vector<int>(101, -1));
    return solve(arr, 1, N - 1);
}