#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k-th smallest element in an array.
 * 
 * This function uses a max-heap to efficiently determine the k-th smallest element
 * in the given array. It iterates through the array, maintaining a max-heap of size k.
 * If the size of the heap exceeds k, the largest element is removed, ensuring that
 * the heap contains the k smallest elements encountered so far. The root of the heap
 * (the largest element in the heap) is the k-th smallest element in the array.
 * 
 * @param n The number of elements in the array.
 * @param k The position (1-based) of the smallest element to find.
 * @param Arr The array of integers.
 * @return int The k-th smallest element in the array.
 */
int kthSmallest(int n, int k, vector<int> Arr)
{
    priority_queue<int> maxh;

    for (int i = 0; i < n; i++)
    {
        maxh.push(Arr[i]);
        if (maxh.size() > k)
            maxh.pop();
    }
    return maxh.top();
}