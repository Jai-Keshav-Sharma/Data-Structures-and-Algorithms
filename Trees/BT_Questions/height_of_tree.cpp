//  LeetCode 104. Maximum Depth of Binary Tree

#include <bits/stdc++.h>
using namespace std;

/*
 * Definition for a binary tree node.
 */
struct TreeNode
/**
 * @brief Definition for a binary tree node.
 *
 * This structure represents a node in a binary tree. Each node contains an integer value,
 * a pointer to the left child node, and a pointer to the right child node.
 */
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        int ans = max(l, r) + 1;

        return ans;
    }
};