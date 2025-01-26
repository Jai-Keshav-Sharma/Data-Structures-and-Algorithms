#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Reverses the first k elements of a given queue.
 *
 * This function takes a queue and an integer k as input and reverses the order
 * of the first k elements of the queue. The remaining elements of the queue
 * remain in their original order.
 *
 * @param q The queue of integers to be modified.
 * @param k The number of elements from the front of the queue to be reversed.
 * @return A queue with the first k elements reversed and the remaining elements
 *         in their original order.
 */
queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();

    if (n == 1)
        return q;

    stack<int> st;

    int i = 0;

    // popping first k elements from thr queue and pushing into stack
    while (i < k)
    {
        st.push(q.front());
        q.pop();
        i++;
    }

    // popping all elements from stack and pushing them into queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // popping remaining (n - k) elements from the starting of the queue and pushing them back into the queue
    int t = 0;
    while (t < n - k)
    {
        int val = q.front();
        q.pop();
        q.push(val);
        t++;
    }
    return q;
}