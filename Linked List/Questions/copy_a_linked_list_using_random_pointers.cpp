// LeetCode 138. Copy List with Random Pointer

#include <bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        Node *temp = head;

        // inserting copy nodes in between og list
        while (temp != nullptr)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        temp = head;

        // connecting random pointers
        while (temp != nullptr)
        {
            Node *copyNode = temp->next;

            if (temp->random == nullptr)
                copyNode->random = nullptr;
            else
                copyNode->random = temp->random->next;
            temp = temp->next->next;
        }

        // dummy head for deep copy list
        Node *d_Node = new Node(-1);
        temp = head;
        Node *res = d_Node;

        // connecting next pointers
        while (temp != nullptr)
        {
            res->next = temp->next;
            temp->next = res->next->next;
            res->next->next = nullptr;

            res = res->next;
            temp = temp->next;
        }

        // extracting the deep copy
        return d_Node->next;
    }
};