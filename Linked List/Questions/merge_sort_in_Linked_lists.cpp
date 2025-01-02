// LeetCode 148. Sort List

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
private:
    ListNode *middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        // dummy node
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;

        // merge two sorted linked lists
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != nullptr)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != nullptr)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        return ans;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // finding middle node
        ListNode *mid = middle(head);

        // setting left as head of left half and right as head of right half
        ListNode *right = head;
        ListNode *left = mid->next;
        mid->next = nullptr;

        // sorting left and right halves
        left = sortList(left);
        right = sortList(right);

        // merging left and right halves
        ListNode *result = merge(left, right);

        return result;
    }
};