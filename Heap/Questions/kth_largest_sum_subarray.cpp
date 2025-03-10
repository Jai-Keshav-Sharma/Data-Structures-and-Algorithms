#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k-th largest sum of subarrays in a given array.
 * 
 * This function calculates the sum of all possible subarrays of the input array
 * and uses a min-heap to keep track of the k largest sums. The top element of 
 * the min-heap after processing all subarrays will be the k-th largest sum.
 * 
 * @param arr The input vector of integers.
 * @param k The k-th position to find the largest sum.
 * @return The k-th largest sum of subarrays.
 */
int kthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum = sum + arr[j];
            minh.push(sum);

            if (minh.size() > k)
            {
                minh.pop();
            }
        }
    }

    return minh.top();
}