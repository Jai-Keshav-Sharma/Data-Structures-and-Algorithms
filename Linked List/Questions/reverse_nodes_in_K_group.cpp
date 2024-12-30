//LeetCode 25. Reverse Nodes in k-Group

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // base case
        if (head->next == nullptr)
            return head;

        // checking if there are at least k nodes to reverse, if not we wont touch them
        ListNode *check = head;
        for (int i = 0; i < k; ++i)
        {
            if (check == nullptr)
                return head;
            check = check->next;
        }

        ListNode *back = nullptr;
        ListNode *curr = head;
        ListNode *front = nullptr;

        // reversing first k nodes using iteration
        int count = 0;
        while (curr != nullptr && count < k)
        {
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
            count++;
        }

        // recursive call for next remaining nodes
        //  this recursive call will return the head of the remaining reversed
        //  list, therefore we have to connct the returned head to the previous
        //  head
        if (front != nullptr)
            head->next = reverseKGroup(front, k);

        return back;
    }
};