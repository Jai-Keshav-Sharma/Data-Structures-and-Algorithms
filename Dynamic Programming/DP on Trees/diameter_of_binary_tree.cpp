//LeetCode 543. Diameter of Binary Tree

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
class Solution {
public:
    /**
     * @brief Helper function to calculate the diameter of a binary tree.
     * 
     * This function computes the height of the tree while updating the diameter
     * (the longest path between any two nodes in the tree) using a reference variable.
     * 
     * @param root Pointer to the root node of the binary tree.
     * @param res Reference to an integer that stores the maximum diameter found so far.
     * @return int The height of the current subtree.
     */
    int solve(TreeNode* root, int& res) {
        if (root == nullptr)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(l, r) + 1;
        int ans = max(temp, l + r + 1);
        res = max(res, ans);

        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res - 1;
        /*-1 bcz this code was intented to return the number of nodes int the
           longest path b/w two nodes   (including the two nodes) /but here what
           they asked is the length of the path which will be the number of
                nodes in the longest path - 1*/
    }
};
