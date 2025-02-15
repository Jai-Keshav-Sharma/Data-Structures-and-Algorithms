// Leetcode 235. Lowest Common Ancestor of a Binary Search Tree

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
{
public:
    /**
     * @brief Finds the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST) using an iterative approach.
     * 
     * This function takes the root of the BST and two nodes P and Q, and returns their LCA. 
     * The LCA of two nodes P and Q in a BST is defined as the lowest node in the tree that has both P and Q as descendants.
     * 
     * @param root Pointer to the root node of the BST.
     * @param P Pointer to the first node.
     * @param Q Pointer to the second node.
     * @return TreeNode* Pointer to the LCA node. If either P or Q is not present in the tree, returns nullptr.
     */
    TreeNode *iterativeSol(TreeNode *root, TreeNode *P, TreeNode *Q)
    {
        if (root == nullptr)
            return root;

        TreeNode *curr = root;

        while (curr)
        {
            if (curr->val < P->val && curr->val < Q->val)
                curr = curr->right;
            else if (curr->val > P->val && curr->val > Q->val)
                curr = curr->left;
            else
            {
                return curr;
            }
        }
        return nullptr;
    }

    /**
     * Function to find the lowest common ancestor (LCA) of two given nodes in a Binary Search Tree (BST).
     * 
     * @param root Pointer to the root node of the BST.
     * @param p Pointer to the first node.
     * @param q Pointer to the second node.
     * @return Pointer to the LCA node of the given nodes p and q.
     * 
     * The function provides two approaches to find the LCA:
     * 1. Recursive Approach (commented out)
     *    - If both p and q lie on the right side of the root, the function recurses on the right subtree.
     *    - If both p and q lie on the left side of the root, the function recurses on the left subtree.
     *    - If one node is on the left and the other is on the right, or if the root is either p or q, the root is the LCA.
     * 
     * 2. Iterative Approach (used in the function)
     *    - The function calls an iterative solution to find the LCA.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // ---------------- RECURSIVE APPROACH----------------
        // if (root == nullptr)
        //     return nullptr;

        // int curr = root->val;

        // if both p and q lie on right side, then goto root -> right
        // if (curr < p->val && curr < q->val)
        //     return lowestCommonAncestor(root->right, p, q);

        // if p and q both lie on the left, then goto root -> left
        // if (curr > p->val && curr > q->val)
        //     return lowestCommonAncestor(root->left, p, q);

        // and if none of the above is the case, then it means that one of them
        // is on the left and one is on the right || root -> val is either q or
        // p in both scenarios, the LCA will be the root
        // return root;

        // --------------------- ITERATIVE APPROACH -------------------------
        return iterativeSol(root, p, q);
    }
};