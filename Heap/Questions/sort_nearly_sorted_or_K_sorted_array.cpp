#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Sorts a nearly sorted (or k-sorted) array.
 * 
 * This function takes an array where each element is at most k positions away from its target position
 * and sorts it using a min-heap.
 * 
 * @param arr The input array to be sorted.
 * @param k The maximum distance (number of positions) each element is away from its target position.
 */
void nearlySorted(vector<int> &arr, int k)
{

    priority_queue<int, vector<int>, greater<int>> minh;

    int i = 0;

    for (auto each : arr)
    {
        minh.push(each);
        if (minh.size() > k)
        {
            arr[i++] = minh.top();
            minh.pop();
        }
    }

    while (!minh.empty())
    {
        arr[i++] = minh.top();
        minh.pop();
    }
}