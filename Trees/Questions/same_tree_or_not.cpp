// LeetCode 100. Same Tree

#include <bits/stdc++.h>
using namespace std;

/**********************************************************

    Following is the Binary Tree Node class structure:
***********************************************************/

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
 * @brief Compares two binary trees to determine if they are identical.
 * 
 * This function checks if two binary trees are structurally identical and 
 * have the same node values. It performs a recursive comparison of the 
 * corresponding nodes in both trees.
 * 
 * @param root1 Pointer to the root node of the first binary tree.
 * @param root2 Pointer to the root node of the second binary tree.
 * @return true if both binary trees are identical, false otherwise.
 */
bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (!root1 || !root2)
        return root1 == root2;

    return root1->data == root2->data and identicalTrees(root1->left, root2->left) and identicalTrees(root1->right, root2->right);
}