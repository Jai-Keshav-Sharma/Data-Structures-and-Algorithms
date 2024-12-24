//LeetCode 887. Super Egg Drop

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> t; // Declare the memoization table as a member variable

    // Constructor to initialize the memoization table
    Solution()
    {
        t = vector<vector<int>>(
            101, vector<int>(100001, -1)); // Initialize in constructor
    }

    /**
     * @brief Computes the minimum number of attempts needed to find the critical floor
     *        from which an egg can be dropped without breaking, using a given number of eggs
     *        and floors.
     * 
     * This function uses dynamic programming and binary search to optimize the solution.
     * 
     * @param k The number of eggs available.
     * @param n The number of floors to test.
     * @return The minimum number of attempts needed in the worst case.
     */
    int superEggDrop(int k, int n)
    {
        if (k == 1)
            return n;
        if (n == 1 || n == 0)
            return n;

        if (t[k][n] != -1)
            return t[k][n];

        int mini = INT_MAX;
        int low = 1;
        int high = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int l = superEggDrop(k - 1, mid - 1);
            int r = superEggDrop(k, n - mid);

            int temp = 1 + max(l, r);
            mini = min(mini, temp);

            // Adjust the binary search based on cases
            if (l > r)
            {
                // if l > r , we move towards l bcz we need worst case
                high = mid - 1; // Move search to lower floors
            }
            else
            {
                // if l < r, we move towards right as we need worst case
                low = mid + 1; // Move search to higher floors
            }
        }
        return t[k][n] = mini;
    }
};
