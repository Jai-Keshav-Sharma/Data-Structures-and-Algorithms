#include <bits/stdc++.h>
using namespace std;

// Following is the Binary Tree Node class structure:

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root, int &count)
{
    if (root == nullptr)
        return;

    solve(root->left, count);

    // checking for leaf node
    if (root->left == nullptr && root->right == nullptr)
        count++;

    solve(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    solve(root, count);
    return count;
}