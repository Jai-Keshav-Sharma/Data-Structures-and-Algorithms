#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *insertIntoBST(Node *&root, int d)
{
    if (root == nullptr)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *&root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

Node * minValue(Node * root) {
    Node * temp = root;
    while(temp -> left) {
        temp = temp -> left;
    }
    return temp;

}

Node * deleteNode(Node * root, int key) {
    if(root == nullptr)
        return nullptr;
    if(root -> data == key) {
        // 0 children
        if(!root -> left && !root -> right) {
            delete root;
            return nullptr;
        }

        // 1 child(left)
        if(root -> left && !root -> right) {
            Node * temp = root -> left;
            delete root;
            return temp;
        }

        // 1 child(right)
        if(root -> left && !root -> right) {
            Node * temp = root -> left;
            delete root;
            return temp;
        }

        //2 children
        if(root -> left && root -> right) {
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteNode(root -> right, mini);
            return root;
        }
    }
    else if(root -> data < key) {
        root -> right = deleteNode(root -> right, key);
        return root;
    }
    else {
        root -> left = deleteNode(root -> left, key);
        return root;
    }
    return nullptr;

}

int main()
{
    Node *root = nullptr;

    cout << "enter data to create BST: " << endl;
    takeInput(root);

    cout << "level order Traversal: " << endl;
    levelOrderTraversal(root);

    // inorder, preorder and postorder also work as same as they work in BT

    return 0;
}