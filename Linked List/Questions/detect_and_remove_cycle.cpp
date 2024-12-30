// Cycle detection and removal using Floyd's Algorithm

#include <bits/stdc++.h>
/******************************************************/

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// this function return the node at which fast and slow becomes equal while
// checking for
//  cycle in the list using Floys's Algorithm
Node *cycle(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return slow;
    }

    // return null bcz no point of intersection found
    return nullptr;
}
Node *removeLoop(Node *head)
{
    Node *instersection = cycle(head);

    // if intersection is null then there is no cycle present, therefore return
    // head
    if (instersection == nullptr)
        return head;

    Node *slow = head;
    Node *fast = instersection;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // now slow is the node at which cycle begins

    Node *prev = slow;
    while (prev->next != slow)
    {
        prev = prev->next;
    }
    // prev now is at one node before the node at which cycle begins, i.e. slow

    prev->next = nullptr;
    return head;
}