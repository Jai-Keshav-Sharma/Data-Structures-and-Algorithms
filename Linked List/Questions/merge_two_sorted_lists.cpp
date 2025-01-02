// LeetCode 21. Merge Two Sorted Lists

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
************************************************************/

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *solve(Node<int> *first, Node<int> *second)
{

    // if there is only one node in first list
    if (first->next == nullptr)
    {
        first->next = second;
        return first;
    }

    Node<int> *curr1 = first;
    Node<int> *next1 = first->next;
    Node<int> *curr2 = second;

    while (next1 != nullptr && curr2 != nullptr)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            // inserting node from second into first
            Node<int> *next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            // updating pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {

            // moving the window ahead
            curr1 = next1;
            next1 = next1->next;

            // if first list becomes empty before second list, then append second list
            // to first and return
            if (next1 == nullptr)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    // this is to make sure that we want to insert nodes from SECOND into FIRST
    // everytime irrespective of that the first element of FIRST is bigger OR
    // first element of SECOND is bigger
    // using this logic we will always be inserting nodes from SECOND into FIRST
    if (first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
}
