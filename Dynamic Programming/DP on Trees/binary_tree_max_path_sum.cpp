//LetCode Problem: 124. Binary Tree Maximum Path Sum

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
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

    /**
     * @brief Computes the maximum path sum in a binary tree.
     * 
     * This function recursively calculates the maximum path sum for a given binary tree node.
     * It updates the result reference with the highest path sum found.
     * 
     * @param root Pointer to the root node of the binary tree.
     * @param res Reference to an integer that stores the maximum path sum found so far.
     * @return int The maximum path sum for the current node.
     */
    int solve(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(max(l, r) + root->val, root->val);
        int ans = max(temp, l + r + root->val);
        res = max(ans, res);

        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};