// LeetCode 98. Validate Binary Search Tree
// most optimal

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
/*************************************************************
 Following is the Binary Tree node structure
 *************************************************************/

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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

/**
 * @brief Validates if a binary tree is a Binary Search Tree (BST).
 *
 * This function uses Morris Inorder Traversal to validate if the given binary tree
 * is a BST. It traverses the tree without using extra space for recursion or a stack.
 *
 * @param root Pointer to the root node of the binary tree.
 * @return true if the binary tree is a BST, false otherwise.
 */
bool validateBST(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return true;

    BinaryTreeNode<int> *curr = root;
    BinaryTreeNode<int> *predec = nullptr;
    int prev = INT_MIN;

    while (curr)
    {
        if (!curr->left)
        {
            if (curr->data <= prev)
                return false;
            prev = curr->data;
            curr = curr->right;
        }
        else
        {
            predec = curr->left;
            while (predec->right != nullptr && predec->right != curr)
            {
                predec = predec->right;
            }

            if (predec->right == nullptr)
            {
                predec->right = curr;
                curr = curr->left;
            }
            else
            {
                predec->right = nullptr;
                if (curr->data <= prev)
                    return false;
                prev = curr->data;
                curr = curr->right;
            }
        }
    }
    return true;
}