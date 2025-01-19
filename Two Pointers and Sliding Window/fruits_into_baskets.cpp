// Leetcode 904. Fruits into Baskets

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Finds the maximum number of fruits that can be collected in two baskets.
     * 
     * This function uses the sliding window technique to determine the maximum number
     * of fruits that can be collected in two baskets. Each basket can only contain one
     * type of fruit, and the goal is to collect the maximum number of fruits while 
     * adhering to this constraint.
     * 
     * @param fruits A vector of integers where each integer represents a type of fruit.
     * @return int The maximum number of fruits that can be collected in two baskets.
     */
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();

        int l = 0;
        int r = 0;
        int maxlen = 0;
        int k = 2; // number of baskets

        unordered_map<int, int> mpp;

        while (r < n)
        {
            mpp[fruits[r]]++;

            if (mpp.size() > k)
            {
                mpp[fruits[l]]--;

                if (mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);

                l++;
            }

            if (mpp.size() <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};