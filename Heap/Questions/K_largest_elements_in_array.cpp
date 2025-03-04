#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the k largest elements in an array.
 *
 * This function takes an array of integers and an integer k, and returns a vector containing the k largest elements from the array in descending order.
 *
 * @param arr A reference to a vector of integers representing the input array.
 * @param k An integer representing the number of largest elements to find.
 * @return A vector of integers containing the k largest elements from the input array in descending order.
 */
vector<int> kLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minh;

    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
            minh.pop();
    }

    while (!minh.empty())
    {
        res.push_back(minh.top());
        minh.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}