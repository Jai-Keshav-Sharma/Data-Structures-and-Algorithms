// LeetCode 215. Kth Largest Element in an Array


#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k-th largest element in an unsorted array.
 * 
 * This function uses a min-heap to efficiently determine the k-th largest element
 * in the given vector of integers. It maintains a heap of size k, ensuring that
 * the smallest element in the heap is the k-th largest element in the array.
 * 
 * @param nums A reference to a vector of integers.
 * @param k An integer representing the k-th position.
 * @return The k-th largest element in the vector.
 */
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();

    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < n; i++)
    {
        minh.push(nums[i]);

        if (minh.size() > k)
            minh.pop();
    }

    return minh.top();
}