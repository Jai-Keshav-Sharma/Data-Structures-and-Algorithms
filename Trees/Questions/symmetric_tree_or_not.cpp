// LeetCode 101. Symmetric Tree

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution
{
private:
    /**
     * @brief Recursively checks if two subtrees are mirror images of each other.
     *
     * This function compares two subtrees to determine if they are symmetric.
     * It checks if the values of the current nodes are equal and then recursively
     * checks the left subtree of the first tree with the right subtree of the second tree,
     * and the right subtree of the first tree with the left subtree of the second tree.
     *
     * @param left Pointer to the root node of the left subtree.
     * @param right Pointer to the root node of the right subtree.
     * @return true if the subtrees are mirror images of each other, false otherwise.
     */
    bool solve(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
            return left == right;

        if (left->val != right->val)
            return false;

        return solve(left->left, right->right) &&
               solve(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return solve(root->left, root->right);
    }
};