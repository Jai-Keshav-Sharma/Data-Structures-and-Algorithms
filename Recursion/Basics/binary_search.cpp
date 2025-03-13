#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs a binary search on a sorted array to find a target value.
 * 
 * This function uses recursion to implement the binary search algorithm.
 * It searches for the target value `k` within the subarray defined by the
 * start index `s` and the end index `e`.
 * 
 * @param arr The sorted array in which to search for the target value.
 * @param s The starting index of the subarray to search.
 * @param e The ending index of the subarray to search.
 * @param k The target value to search for.
 * @return true If the target value `k` is found in the array.
 * @return false If the target value `k` is not found in the array.
 */
bool binarySearch(int arr[], int s, int e, int k)
{
    if (s > e)
    {
        return false;
    }

    int mid = (s + e) / 2;

    if (arr[mid] == k)
    {
        return true;
    }
    if (arr[mid] > k)
    {
        return binarySearch(arr, s, mid - 1, k);
    }
    else if (arr[mid] < k)
    {
        return binarySearch(arr, mid + 1, e, k);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;
    if (binarySearch(arr, 0, n - 1, x))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not found";
    }

    return 0;
}