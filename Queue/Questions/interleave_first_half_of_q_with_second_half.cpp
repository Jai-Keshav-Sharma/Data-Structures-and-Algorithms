#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Rearranges the elements of the given queue by interleaving the first half with the second half.
 *
 * This function takes a queue of integers and rearranges its elements such that the first half of the queue
 * is interleaved with the second half. For example, if the queue contains {1, 2, 3, 4, 5, 6}, the function
 * will rearrange it to {1, 4, 2, 5, 3, 6}.
 *
 * @param q A reference to the queue of integers to be rearranged.
 * @return A vector of integers containing the rearranged elements of the queue.
 */
vector<int> rearrangeQueue(queue<int> &q)
{
    int n = q.size();

    queue<int> newq;
    vector<int> res;

    // pushing first half elements of q to newq and popping them
    for (int i = 0; i < n / 2; i++)
    {
        newq.push(q.front());
        q.pop();
    }

    // interleaving elements using q and newq
    while (!newq.empty())
    {
        q.push(newq.front());
        q.push(q.front());

        q.pop();
        newq.pop();
    }

    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}