#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long kth_smallest(long long A[], int k, int N)
    {
        priority_queue<int> maxh;

        for (int i = 0; i < N; i++)
        {
            maxh.push(A[i]);

            if (maxh.size() > k)
            {
                maxh.pop();
            }
        }

        return maxh.top();
    }

    /**
     * @brief Calculates the sum of elements between the K1-th smallest and K2-th smallest elements in the array.
     * 
     * This function finds the K1-th smallest and K2-th smallest elements in the array A, and then calculates the sum of all elements that are greater than the K1-th smallest element and less than the K2-th smallest element.
     * 
     * @param A The array of elements.
     * @param N The number of elements in the array.
     * @param K1 The position of the first smallest element to consider.
     * @param K2 The position of the second smallest element to consider.
     * @return The sum of elements between the K1-th smallest and K2-th smallest elements.
     */
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        long long k1 = kth_smallest(A, K1, N);
        long long k2 = kth_smallest(A, K2, N);

        long long sum = 0;

        for (int i = 0; i < N; i++)
        {
            if (A[i] < k2 and A[i] > k1)
            {
                sum += A[i];
            }
        }

        return sum;
    }
};
