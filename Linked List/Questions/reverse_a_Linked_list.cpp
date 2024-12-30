// LeetCode 206. Reverse Linked List

struct ListNode
{
    int val;
    ListNode *next;
    // Node() : val(0), next(nullptr) {}
    // Node(int x) : val(x), next(nullptr) {}
    // Node(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /*  OPTIMAL APPROACH -I (ITERATIVE)
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    */

    // APPROACH - II

    ListNode *solve(ListNode *&head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *smallHead = solve(head->next);
        head->next->next = head;
        head->next = nullptr;

        return smallHead;
    }
};