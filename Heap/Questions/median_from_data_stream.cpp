// LeetCode 295. Find Median from Data Stream
#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

public:
    MedianFinder() {}

    /**
     * @brief Adds a number into the data structure.
     * 
     * This function inserts a number into one of the two heaps (max-heap or min-heap)
     * based on its value relative to the current elements in the heaps. It ensures
     * that the heaps remain balanced such that the difference in size between the
     * two heaps is at most 1.
     * 
     * @param num The number to be added to the data structure.
     */
    void addNum(int num)
    {
        // if max-heap is empty(i.e. in the beginning) or if num < maxh.top(),
        // push into max-heap
        if (maxh.empty() || maxh.top() > num)
        {
            maxh.push(num);
        }
        else
        { // else push into min heap
            minh.push(num);
        }

        // balancing
        if (maxh.size() > minh.size() + 1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        if (minh.size() > maxh.size() + 1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian()
    {
        double median;
        if (minh.size() > maxh.size())
        {
            median = minh.top();
        }
        else if (maxh.size() > minh.size())
        {
            median = maxh.top();
        }
        else
        {
            median = (minh.top() + maxh.top()) / 2.0;
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */