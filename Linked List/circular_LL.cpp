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

void insertNode(Node *&tail, int element, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        tail = newNode;
        newNode->next = newNode;
    }

    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void deleteNode(Node *&tail, int element)
{
    if (tail == nullptr)
        return;

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    // single element in LL
    if (curr == prev)
    {
        tail = nullptr;
    }

    if (tail == curr)
    {
        tail = prev;
    }

    curr->next = nullptr;
    delete curr;
}

void print(Node *&tail)
{
    if (tail == nullptr)
    {
        cout << "list is empty!" << endl;
        return;
    }
    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = nullptr;

    insertNode(tail, 0, 5);
    // print(tail);

    insertNode(tail, 5, 10);
    deleteNode(tail, 5);
    print(tail);
    // print(tail);
    // insertNode(tail, 10, 20);
    // print(tail);
    // insertNode(tail, 20, 30);
    // print(tail);
    // insertNode(tail, 30, 40);
    // print(tail);
    // insertNode(tail, 10, 15);
    // print(tail);
    // // cout << tail -> data << endl;

    // deleteNode(tail, 10);
    // print(tail);

    // deleteNode(tail, 5);
    // print(tail);

    return 0;
}