// LeetCode 23. Merge k Sorted Lists

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution
{
public:
    /**
     * @brief Merges k sorted linked lists into one sorted linked list.
     *
     * This function takes a vector of k sorted linked lists and merges them into a single sorted linked list.
     * It uses a min-heap (priority queue) to efficiently find the smallest element among the heads of the lists.
     *
     * @param lists A vector of pointers to the heads of k sorted linked lists.
     * @return ListNode* A pointer to the head of the merged sorted linked list.
     *
     * The function works as follows:
     * 1. Initialize a min-heap to store the nodes of the linked lists.
     * 2. Create a dummy node to serve as the head of the merged list.
     * 3. Push the head nodes of all the lists into the min-heap.
     * 4. Extract the smallest node from the min-heap and add it to the merged list.
     * 5. If the extracted node has a next node, push it into the min-heap.
     * 6. Repeat steps 4 and 5 until the min-heap is empty.
     * 7. Return the next node of the dummy node, which is the head of the merged list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minh;
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        // pushinng heads of all lists into min-heap
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                minh.push(lists[i]);
        }

        // extracting the top() from min-heap and pushing in dummy list (answer
        // list to be returned)
        while (!minh.empty())
        {
            ListNode *temp = minh.top();
            minh.pop();

            current->next = temp;
            current = current->next;

            // if there is a next node present in the current list, then push it
            // to min-heap
            if (temp->next)
            {
                minh.push(temp->next);
            }
            // otherwise it will move to the next list as the last element of
            // the previous list is popped already from the heap; the top() is
            // now the node of the next list
        }

        return dummy->next;
    }
};