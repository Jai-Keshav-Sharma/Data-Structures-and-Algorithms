// LeetCode 1382. Balance a Binary Search Tree

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
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    /**
     * @brief Constructs a balanced binary search tree (BST) from a sorted array.
     * 
     * This function recursively constructs a balanced BST by selecting the middle element
     * of the current subarray as the root and recursively doing the same for the left and
     * right subarrays.
     * 
     * @param s The starting index of the current subarray.
     * @param e The ending index of the current subarray.
     * @param res A reference to the sorted array from which the BST is to be constructed.
     * @return TreeNode* A pointer to the root of the balanced BST.
     */
    TreeNode *solve(int s, int e, vector<int> &res)
    {
        if (s > e)
            return nullptr;

        int mid = s + (e - s) / 2;
        TreeNode *root = new TreeNode(res[mid]);

        root->left = solve(s, mid - 1, res);
        root->right = solve(mid + 1, e, res);
        return root;
    }

public:
    /**
     * @brief Balances a Binary Search Tree (BST).
     * 
     * This function takes the root of a BST and returns a new root of a balanced BST.
     * It first performs an inorder traversal to get the elements in sorted order,
     * then constructs a balanced BST from the sorted elements.
     * 
     * @param root The root node of the BST to be balanced.
     * @return TreeNode* The root node of the balanced BST.
     */
    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        vector<int> res;
        inorder(root, res);

        return solve(0, res.size() - 1, res);
    }
};