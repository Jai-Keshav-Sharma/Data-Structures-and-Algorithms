// LeetCode 60. Permutation Sequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Generates the k-th permutation sequence of numbers from 1 to n.
     * 
     * This function computes the k-th permutation sequence of the set {1, 2, ..., n}
     * using a mathematical approach based on factorials to determine the position
     * of each digit in the sequence. It avoids generating all permutations, making
     * it efficient for large values of n.
     * 
     * @param n The size of the set {1, 2, ..., n}.
     * @param k The 1-based index of the desired permutation sequence.
     * @return A string representing the k-th permutation sequence.
     * 
     * @note The function assumes that 1 <= n <= 9 and 1 <= k <= n!.
     *       For larger values of n, the factorial values may exceed the range of int.
     */
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> nums; // stores numbers from 1 to n;

        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans = "";
        // since we are considering zero based indexing
        k = k - 1;

        while (true)
        {
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);

            if (nums.size() == 0)
                break;

            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};