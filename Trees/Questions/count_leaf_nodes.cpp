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

/**
 * @brief Counts the number of leaf nodes in a binary tree.
 *
 * This function recursively traverses the binary tree and increments the count
 * whenever a leaf node is encountered. A leaf node is defined as a node with no
 * children (both left and right pointers are null).
 *
 * @param root Pointer to the root node of the binary tree.
 * @param count Reference to an integer that will store the count of leaf nodes.
 */
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