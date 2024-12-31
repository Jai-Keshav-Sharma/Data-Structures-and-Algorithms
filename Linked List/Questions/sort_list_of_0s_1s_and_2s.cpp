#include <bits/stdc++.h>
using namespace std;
/*
Following is the class structure of the Node class:
*/

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

/**
 * @brief Sorts a linked list of 0s, 1s, and 2s.
 * 
 * This function takes the head of a linked list where each node contains 
 * data that is either 0, 1, or 2. It sorts the linked list such that all 
 * nodes containing 0s come first, followed by nodes containing 1s, and 
 * then nodes containing 2s.
 * 
 * @param head Pointer to the head of the linked list.
 * @return Node* Pointer to the head of the sorted linked list.
 * 
 * The function works by creating three dummy lists for 0s, 1s, and 2s. 
 * It then traverses the original list and appends each node to the 
 * corresponding dummy list. Finally, it connects the three lists together 
 * and returns the head of the sorted list.
 * 
 * The function handles edge cases where the list might not contain any 
 * 1s or 2s. It ensures that the final list is properly terminated with 
 * a nullptr.
 */
Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    // creating dummy lists
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    // these pointers act as tails of dummy lists
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    // handling the case where there are no ones in the list
    //  Note : the code will automatically handle the cases when there are no zero
    //  nodes or no two nodes
    (oneHead->next == nullptr) ? zero->next = twoHead->next
                               : zero->next = oneHead->next;

    // connecting the one to two
    one->next = twoHead->next;

    // connecting two to nullptr
    two->next = nullptr;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}