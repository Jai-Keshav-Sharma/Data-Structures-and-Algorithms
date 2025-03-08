#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

class Solution
{
public:
    /**
     * @brief Finds the k closest points to the origin (0, 0) from a given list of points.
     *
     * This function uses a max heap to keep track of the k closest points to the origin.
     * The distance is calculated using the squared Euclidean distance to avoid unnecessary
     * square root calculations.
     *
     * @param points A vector of vectors where each inner vector represents a point with x and y coordinates.
     * @param k The number of closest points to find.
     * @return A vector of vectors containing the k closest points to the origin.
     */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<ppi> maxh;
        vector<vector<int>> res;

        for (auto it : points)
        {
            // order of distances will be the same if we square root them, so to
            // reduce our calculations, we avoid that and simply square and add
            int dist = pow(it[0], 2) + pow(it[1], 2);
            maxh.push({dist, {it[0], it[1]}});

            if (maxh.size() > k)
            {
                maxh.pop();
            }
        }

        while (!maxh.empty())
        {
            res.push_back({maxh.top().second.first, maxh.top().second.second});
            maxh.pop();
        }

        return res;
    }
};