// LeetCode 658. Find K Closest Elements

#include <bits/stdc++.h>
using namespace std;


// BETTER APPROACH------- O(NLOGK) TIME
/**
 * @brief Finds the k closest elements to a given value x in the array.
 * 
 * This function uses a max heap to keep track of the k closest elements to x.
 * It iterates through the array, pushing elements into the heap based on their
 * absolute difference from x. If the heap size exceeds k, the element with the
 * largest difference is removed. Finally, the elements in the heap are collected,
 * sorted, and returned.
 * 
 * @param arr The input array of integers.
 * @param k The number of closest elements to find.
 * @param x The target value to find the closest elements to.
 * @return A vector containing the k closest elements to x, sorted in ascending order.
 */
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> maxh;
    int n = arr.size();
    
    vector<int> res;
    
    for (int i = 0; i < n; i++)
    {
        maxh.push({abs(arr[i] - x), arr[i]});
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    
    while (!maxh.empty())
    {
        res.push_back(maxh.top().second);
        maxh.pop();
    }
    sort(res.begin(), res.end());
    return res;
}


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
// OPTIMAL APPROACH------O(LOG(N - K)) TIME
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
