#include <bits/stdc++.h>
using namespace std;
/********************************
********************************/
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


void splitCircularList(Node *head) {
  if (head == nullptr) {
    return;
  }

  Node *slow = head;
  Node *fast = head;

  // this logic of finding the middle node is tweaked a bit for handling both
  // cases
  //  when N is odd and N is even
  while (fast->next != head && fast->next->next != head) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // if N is even, {fast -> next} is the last node of second half
  // if N is odd, {fast} is the last node of second half
  // slow will be the middle node in both the cases

  Node *h1 = slow;       // last node of first half
  Node *h2 = fast->next; // since here N is even(given)

  h2->next = slow->next;
  h1->next = head;
}
