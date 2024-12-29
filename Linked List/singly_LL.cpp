#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        if (this->next != nullptr)
        {
            delete this->next;
            this->next = nullptr;
        }
    }
};

// inserting new node at head
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;

    head = temp;
}

// inserting new node at end
void insertAtTail(Node *&tail, int data)
{

    Node *newNode = new Node(data);
    newNode->next = nullptr;
    tail->next = newNode;

    tail = newNode;
}

// inserting at a given position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    // edge case
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1; // starting from the first node

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // edge case
    if (temp->next == nullptr)
    {
        insertAtTail(tail, data);
        return;
    }

    // creating new node to be inserted
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// delete node at position
void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    // base case
    if (head == nullptr)
        return;

    Node *temp = head;
    int cnt = 1;

    // if node to be deleted is first node
    if (position == 1)
    {
        head = head->next;
        delete temp;
        return;
    }

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    } // temp is now the node previous to the node to be deleted

    // updating tail in case the last node needs to be deleted
    if (temp->next == tail)
    {
        tail = temp;
    }

    Node *toBeDeleted = temp->next;
    temp->next = toBeDeleted->next;

    delete toBeDeleted;
}

// printing Linked List
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

int main()
{
    Node *n1 = new Node(10);

    // cout << n1->data << endl;
    // cout << n1->next << endl;

    Node *head = n1;
    Node *tail = n1;
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtHead(head, 30);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertAtTail(tail, 80);
    print(head);

    insertAtPosition(head, tail, 5, 60);
    print(head);

    // edge case for insertion at given position
    insertAtPosition(head, tail, 7, 5);
    print(head);

    deleteAtPosition(head, tail, 7);
    print(head);

    // verifying head and tail
    cout << head->data << endl;
    cout << tail->data << endl;

    return 0;
}