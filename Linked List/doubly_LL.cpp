#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = nullptr;
    Node *next = nullptr;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// insert at head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }

    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// insert at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {

        tail = newNode;
        head = newNode;
    }

    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;

        tail = newNode;
    }
}

// insert at given position
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int cnt = 1;
    Node *temp = head;

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == nullptr)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
}

// delete at position
void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == nullptr)
        return;

    Node *currNode = head;

    if (position == 1)
    {
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // list is empty
        }
        delete currNode;
        return;
    }

    int cnt = 1;

    while (cnt < position)
    {
        currNode = currNode->next;
        cnt++;
    }

    if (currNode == nullptr)
        return; // if position is greater than the length

    if (currNode->next == nullptr)
    {
        tail = currNode->prev;
        tail->next = nullptr;
        delete currNode;
        return;
    }

    Node *prevNode = currNode->prev;
    Node *nextNode = currNode->next;

    if (prevNode != nullptr)
        prevNode->next = nextNode;

    if (nextNode != nullptr)
        nextNode->prev = prevNode;

    delete currNode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    // Node * n1 = new Node(10);
    Node *head = nullptr;
    Node *tail = nullptr;

    // print(head);
    // cout << length(head) << endl;

    insertAtHead(head, tail, 9);
    print(head);

    insertAtHead(head, tail, 8);
    print(head);

    insertAtTail(head, tail, 11);
    print(head);

    insertAtTail(head, tail, 12);
    print(head);

    insertAtPosition(head, tail, 15, 3);
    print(head);

    insertAtPosition(head, tail, 20, 6);
    print(head);

    deleteAtPosition(head, tail, 3);
    print(head);

    cout << head->data << endl;
    cout << tail->data << endl;

    return 0;
}