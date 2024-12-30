#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<Node*> st;
    Node* temp = head;

    while (temp != nullptr) {
        st.push(temp);
        temp = temp->next;
    }

    head = st.top();
    st.pop();
    head->prev = nullptr;
    Node* bwd = head;

    while (!st.empty()) {
        temp = st.top();
        st.pop();
        bwd->next = temp;
        temp->prev = bwd;
        bwd = temp;
    }

    bwd->next = nullptr;
    return head;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original List: ";
    printList(head);

    head = reverseDLL(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}