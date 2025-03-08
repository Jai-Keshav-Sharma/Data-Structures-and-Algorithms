#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ppi;

struct comparator
{
    /**
     * @brief Comparator function object for comparing pairs of integers.
     * 
     * This comparator is used to compare two pairs of integers (ppi) based on their first and second elements.
     * 
     * @param a The first pair of integers to compare.
     * @param b The second pair of integers to compare.
     * @return true if the first pair should come before the second pair, false otherwise.
     * 
     * The comparison is done as follows:
     * - If the first elements of both pairs are equal, the pair with the smaller second element comes first.
     * - Otherwise, the pair with the larger first element comes first.
     */
    bool operator()(ppi a, ppi b)
    {
        if (a.first == b.first)
        {
            return b.second > a.second;
        }
        return a.first > b.first;
    }
};

int main()
{
    vector<pair<int, int>> v;

    v.push_back({1, 8});
    v.push_back({2, 6});
    v.push_back({3, 3});
    v.push_back({4, 2});
    v.push_back({4, 5});
    v.push_back({5, 9});

    sort(v.begin(), v.end(), comparator());

    for (auto each : v)
    {
        cout << each.first << " " << each.second << endl;
    }

    return 0;
}