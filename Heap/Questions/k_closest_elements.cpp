// LeetCode 658. Find K Closest Elements

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k closest elements to a given value x in a sorted array.
 *
 * This function takes a sorted array `arr`, an integer `k`, and an integer `x`.
 * It returns a vector containing the k closest elements to `x` in the array.
 * The result is sorted in ascending order.
 *
 * @param arr The input sorted array of integers.
 * @param k The number of closest elements to find.
 * @param x The target value to find the closest elements to.
 * @return A vector containing the k closest elements to x in ascending order.
 */
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int l = 0;
    int n = arr.size();
    vector<int> res;
    int r = n - k;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (x - arr[mid] <= arr[mid + k] - x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    for (int i = l; i < l + k; i++)
    {
        res.push_back(arr[i]);
    }
    return res;
}