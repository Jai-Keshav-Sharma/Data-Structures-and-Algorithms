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

Node *buildTree(Node *root)
{
    cout << "enter the data: " << endl;

    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "enter the data for the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            // purana level completely traverse ho chuka h
            cout << endl;
            if (!q.empty())
            {
                // q still has some elements
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }
}

void inOrder(Node *root)
{
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *buildFromLevelOrder(Node *root)
{
    queue<Node *> q;

    cout << "enter data for root node: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "enter data for left of: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "enter data for right of: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

Node *inOrderPredecessor(Node *root)
{
    if (root->left == nullptr)
        return root;

    Node *temp = root;
    temp = temp->left;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}

void MorrisTraversalInorder(Node *root)
{
    if (root == nullptr)
        return;

    Node *temp = root;
    Node *predec = nullptr;

    while (temp != nullptr)
    {
        if (temp->left == nullptr)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        else
        {
            predec = temp->left;

            while (predec->right != nullptr && predec->right != temp)
            {
                predec = predec->right;
            }

            if (predec->right == nullptr)
            {
                predec->right = temp;
                temp = temp->left;
            }
            else
            {
                predec->right = nullptr;
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
    }
}

void MorrisTraversalPreorder(Node *root)
{
    if (root == nullptr)
        return;

    Node *temp = root;
    Node *predec = nullptr;

    while (temp != nullptr)
    {
        if (temp->left == nullptr)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        else
        {
            predec = temp->left;

            while (predec->right != nullptr && predec->right != temp)
            {
                predec = predec->right;
            }

            if (predec->right == nullptr)
            {
                predec->right = temp;
                cout << temp->data << " ";
                temp = temp->left;
            }
            else
            {
                predec->right = nullptr;
                temp = temp->right;
            }
        }
    }
}

int main()
{
    Node *root = nullptr;

    root = buildFromLevelOrder(root);

    // creating a tree

    // root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout << "printing the level order traversal: " << endl;
    // levelOrderTraversal(root);

    cout << "\nInorder traversal is: " << endl;
    inOrder(root);

    cout << "\nPreorder traversal is: " << endl;
    preOrder(root);

    cout << "\nMorris traversal (Inorder) is: " << endl;
    MorrisTraversalInorder(root);

    cout << "\nMorris traversal(Preorder) is: " << endl;
    MorrisTraversalPreorder(root);

    return 0;
}