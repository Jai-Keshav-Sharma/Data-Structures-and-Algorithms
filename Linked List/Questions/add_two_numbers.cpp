// LeetCode 2. Add Two Numbers

//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
private:
    Node * reverse(Node * head) {
        Node * curr = head;
        Node * prev = nullptr;
        Node * front = nullptr;
        
        while(curr != nullptr) {
            front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    
    void insertAtTail(Node * &head, Node * &tail, int value) {
        Node * newNode = new Node(value);
        
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
            
        }
        else {
            tail -> next = newNode;
            tail = newNode;
            tail -> next = nullptr;
            
        }
        return;
    }
    
    Node * solve(Node * first, Node * second) {
        
        int carry = 0;
        
        Node * ansHead = nullptr;
        Node * ansTail = nullptr;
        
        while(first != nullptr || second != nullptr || carry != 0) {
            int val1 = 0;
            if(first != nullptr)
                val1 = first->data;
            
            int val2 = 0;
            if(second != nullptr)
                val2 = second->data;
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            if(first != nullptr) {
                first = first -> next;
            }
            if(second != nullptr) {
                second = second -> next;
            }
        }
        return ansHead;
        
    }
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        Node * first = num1;
        Node * second = num2;
        
        first = reverse(first);
        second = reverse(second);
        
        Node* ans = solve(first, second);
        ans = reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends