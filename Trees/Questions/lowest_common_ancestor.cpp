// LeetCode 236. Lowest Common Ancestor of a Binary Tree

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
/**
 * @brief Finds the lowest common ancestor (LCA) of two nodes in a binary tree.
 * 
 * This function takes the root of a binary tree and two nodes, p and q, and 
 * returns their lowest common ancestor. The LCA of two nodes p and q in a 
 * binary tree is defined as the lowest node that has both p and q as 
 * descendants (where we allow a node to be a descendant of itself).
 * 
 * @param root The root of the binary tree.
 * @param p The first node.
 * @param q The second node.
 * @return TreeNode* The lowest common ancestor of nodes p and q.
 *         If either p or q is not present in the tree, the function returns nullptr.
 *         If both p and q are the same node, the function returns that node.
 */
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // if at some node, both left and right are not null, then its surely
        // the LCA
        if (left && right)
            return root;

        // if left is NULL, then return right and vice-versa
        return left ? left : right;
    }
};