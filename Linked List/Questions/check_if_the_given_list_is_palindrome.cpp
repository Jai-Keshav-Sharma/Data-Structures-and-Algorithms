//LeetCode 234. Palindrome Linked List

#include<bits/stdc++.h>
using namespace std;
/****************************************************************

    Following is the class structure of the Node class:
*****************************************************************/

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
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };


// funtion to get middle of the linked list
Node *getMid(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// to reverse the list
Node *reverse(Node *head) {
  Node *curr = head;
  Node *prev = nullptr;
  Node *front = nullptr;

  while (curr != nullptr) {
    front = curr->next;
    curr->next = prev;
    prev = curr;
    curr = front;
  }
  return prev;
}

bool isPalindrome(Node *head) {
  if (head == nullptr)
    return true;
  if (head->next == nullptr)
    return true;

  // getting mid
  Node *mid = getMid(head);
  Node *temp = mid->next;

  mid->next = reverse(temp);

  Node *newHead = mid->next; // points to the first node of second
                             // half
  Node *oldHead = head;

  while (newHead != nullptr) {
    if (oldHead->data != newHead->data)
      return false;
    oldHead = oldHead->next;
    newHead = newHead->next;
  }

  // reversing again the second half so the original list remains intact
  temp = mid->next;
  mid->next = reverse(temp);

  return true;
}