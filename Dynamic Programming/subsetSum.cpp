#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Determines if there is a subset of the given array with a sum equal to the given sum.
 * 
 * This function uses dynamic programming to solve the subset sum problem. It initializes a 
 * 2D array `t` where `t[i][j]` will be true if there is a subset of the first `i` elements 
 * of the array that has a sum equal to `j`. The function then fills this table based on 
 * whether the current element can be included in the subset or not.
 * 
 * @param arr The array of integers.
 * @param n The number of elements in the array.
 * @param sum The target sum to find in the subset.
 * @return true if there is a subset of the array with a sum equal to the given sum, false otherwise.
 */
bool subsetSum(int arr[], int n, int sum)
{
    //initialisation
    int t[n + 1][sum + 1];
    for(int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }
    for(int j = 0; j < sum + 1; j++)
    {
        t[0][j] = false;
    }//initialisation done

    //filling table    
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < sum + 1; j++)
        {
            if(arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i -1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main() {
    int arr[] = {2, 3, 7, 8, 10};
    int n = 5;
    int sum = 11;
    if(subsetSum(arr, n, sum))  cout << "YES";
    else
        cout << "NO";

    return 0;
}