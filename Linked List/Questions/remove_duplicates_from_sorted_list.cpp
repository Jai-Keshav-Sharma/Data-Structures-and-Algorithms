//LeetCode 83. Remove Duplicates from Sorted List

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *curr = head->next;
        ListNode *prev = head;

        while (curr != nullptr)
        {
            if (curr->val == prev->val)
            {
                ListNode *toDelete = curr;
                prev->next = toDelete->next;
                curr = curr->next;
                toDelete->next = nullptr;
                delete toDelete;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};