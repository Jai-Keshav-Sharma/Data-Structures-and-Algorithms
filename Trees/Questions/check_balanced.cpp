// LeetCode 110.  Balanced Binary Tree

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
public:
    /**
     * @brief Recursively checks if a binary tree is height-balanced.
     * 
     * A binary tree is height-balanced if the difference between the heights
     * of the left and right subtrees of any node is not more than 1.
     * 
     * @param root Pointer to the root node of the binary tree.
     * @return int The height of the tree if it is balanced, otherwise -1.
     * 
     * The function returns:
     * - The height of the tree if it is balanced.
     * - -1 if the tree is not balanced.
     */
    int solve(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int l = solve(root->left);
        if (l == -1)
            return -1;

        int r = solve(root->right);
        if (r == -1)
            return -1;

        if (abs(l - r) > 1)
            return -1;

        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode *root) { return solve(root) != -1; }
};