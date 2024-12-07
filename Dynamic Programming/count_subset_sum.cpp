#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Counts the number of subsets in the given array that sum up to a specified value.
 * 
 * This function uses dynamic programming to find the number of subsets within an array
 * that add up to a given sum. It initializes a 2D table where the rows represent the 
 * elements of the array and the columns represent the possible sums from 0 to the given sum.
 * 
 * @param arr The array of integers.
 * @param sum The target sum for the subsets.
 * @param n The number of elements in the array.
 * @return int The number of subsets that sum up to the given value.
 */
int countSubsetSum(int arr[], int sum, int n)
{
    //initialisation
    int t[n + 1][sum + 1];
    for(int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for(int j = 1; j < sum + 1; j++)
    {
        t[0][j] = 0;
    }//initialisation
    
    //filling table
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < sum + 1; j++)
        {
            if(arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main() {
    int arr[] = {2, 3, 5, 6, 8 ,10};
    int n = 6;
    int sum = 10;
    
    cout << countSubsetSum(arr, sum, n);
    
    return 0;
}