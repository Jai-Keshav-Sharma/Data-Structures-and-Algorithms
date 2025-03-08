// LeetCode 1636. Sort Array by Increasing Frequency

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ppi;

struct comparator
{
    bool operator()(ppi a, ppi b)
    {
        if (a.first == b.first)
        {
            return b.second > a.second;
        }
        return a.first > b.first;
    }
};

class Solution
{
public:
    /**
     * @brief Sorts the elements of the input vector based on their frequency in ascending order.
     *
     * This function takes a vector of integers and sorts the elements based on their frequency.
     * Elements with lower frequency come first. If two elements have the same frequency, their
     * relative order is determined by their value.
     *
     * @param nums A reference to a vector of integers to be sorted based on frequency.
     * @return A vector of integers sorted based on their frequency in ascending order.
     */
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        priority_queue<ppi, vector<ppi>, comparator> minh;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (auto it = mpp.begin(); it != mpp.end(); it++)
        {
            minh.push({it->second, it->first});
        }

        while (!minh.empty())
        {
            int freq = minh.top().first;
            int element = minh.top().second;

            for (int i = 0; i < freq; i++)
            {
                res.push_back(element);
            }
            minh.pop();
        }

        return res;
    }
};
