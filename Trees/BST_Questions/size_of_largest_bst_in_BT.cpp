// Coding Ninjas - Size of largest BST in a Binary Tree

#include <bits/stdc++.h>
using namespace std;

/*
Following is Binary Tree Node structure:
*/
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class NodeValue
{
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

/**
 * @brief Helper function to find the size of the largest BST in a binary tree.
 *
 * This function recursively checks each subtree to determine if it is a BST.
 * It returns a NodeValue object containing the minimum and maximum values in the subtree,
 * and the size of the largest BST found within the subtree.
 *
 * @param root Pointer to the root node of the current subtree.
 * @return NodeValue object containing:
 *         - minNode: Minimum value in the subtree.
 *         - maxNode: Maximum value in the subtree.
 *         - maxSize: Size of the largest BST in the subtree.
 */
NodeValue largestBSTHelper(TreeNode *root)
{
    if (root == nullptr)
        return NodeValue(INT_MAX, INT_MIN, 0);

    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);

    if (left.maxNode < root->data && right.minNode > root->data)
    {
        return NodeValue(min(left.minNode, root->data), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode *root)
{
    if (root == nullptr)
        return -1;

    return largestBSTHelper(root).maxSize;
}