#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if the given array is sorted in non-decreasing order.
 * 
 * This function uses recursion to determine if the array is sorted.
 * It checks the first two elements and then recursively checks the rest of the array.
 * 
 * @param arr The array to be checked.
 * @param n The number of elements in the array.
 * @return true If the array is sorted in non-decreasing order.
 * @return false If the array is not sorted in non-decreasing order.
 */
bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }

    bool remPart = isSorted(arr + 1, n - 1);
    return remPart;
}

int main()
{
    int arr[] = {1, 2, 3, 6, 5};
    if (isSorted(arr, 5))
    {
        cout << "Sorted";
    }
    else
    {
        cout << "Not sorted";
    }

    return 0;
}