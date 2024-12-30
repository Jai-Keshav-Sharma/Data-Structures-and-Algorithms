#include <bits/stdc++.h>
/****************************************************************
    Following is the class structure of the Node class:
*****************************************************************/

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

bool circularLL(Node *head)
{
    if (head->next == nullptr)
        return false;

    Node *temp = head->next;
    while (temp != nullptr && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
        return true;
    return false;
}
