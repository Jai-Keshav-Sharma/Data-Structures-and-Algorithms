// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Determines if there is a subset of the given array with a sum equal to the given sum.
 * 
 * This function uses dynamic programming to solve the subset sum problem. It initializes a 
 * 2D array `t` where `t[i][j]` will be true if there is a subset of the first `i` elements 
 * that has a sum equal to `j`. The function then fills this table based on the choices of 
 * including or excluding the current element.
 * 
 * @param arr The array of integers.
 * @param sum The target sum to check for.
 * @param n The number of elements in the array.
 * @return true If there is a subset of the array with a sum equal to the given sum.
 * @return false Otherwise.
 */
bool subsetSum(int arr[], int sum, int n)
{
    // initialisation
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        t[0][j] = false;
    } // initialisation

    // filling table
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

bool equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum & 1)
        return false;
    else if (sum % 2 == 0)
        return subsetSum(arr, sum / 2, n);
    return false;
}

int main()
{
    int arr[] = {1, 5, 5, 11};
    int n = 4;

    if (equalSumPartition(arr, n))
    {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}