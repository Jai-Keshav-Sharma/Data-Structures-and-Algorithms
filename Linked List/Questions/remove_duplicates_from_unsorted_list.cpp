#include <bits/stdc++.h>
using namespace std;
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

Node *removeDuplicates(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    unordered_set<int> s;
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (s.find(temp->data) != s.end())
        {
            Node *toDelete = temp;
            prev->next = toDelete->next;
            temp = temp->next;
            toDelete->next = nullptr;
            delete toDelete;
            continue;
        }
        s.insert(temp->data);
        prev = temp;
        temp = temp->next;
    }
    return head;
}