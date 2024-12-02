#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the sum of elements in an array using recursion.
 * 
 * This function takes an array and its size as input and returns the sum of its elements.
 * It uses a recursive approach to calculate the sum.
 * 
 * @param arr The array of integers.
 * @param n The number of elements in the array.
 * @return The sum of the elements in the array.
 */
int arrSum(int arr[], int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return arr[0];
    }

    // preocesiong the first element
    int sum = 0;
    sum = sum + arr[0];

    // return the sum of the first element and the sum of the rest of the array
    int remPart = arrSum(arr + 1, n - 1);
    return remPart;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << arrSum(arr, 5);

    return 0;
}