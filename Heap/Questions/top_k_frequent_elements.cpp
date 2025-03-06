// LeetCode 347. Top K Frequent Elements

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
/**
 * @brief Finds the top K frequent elements in the given array.
 *
 * This function takes a vector of integers and an integer k, and returns a vector of the k most frequent elements in the array.
 * It uses an unordered map to count the frequency of each element and a min-heap (priority queue) to keep track of the top k elements.
 *
 * @param nums A vector of integers representing the input array.
 * @param k An integer representing the number of top frequent elements to return.
 * @return A vector of integers containing the top k frequent elements.
 */
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    vector<int> res;
    priority_queue<ppi, vector<ppi>, greater<ppi>> minh;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        minh.push({it->second, it->first});
        if (minh.size() > k)
            minh.pop();
    }

    while (!minh.empty())
    {
        res.push_back(minh.top().second);
        minh.pop();
    }
    return res;
}