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
     * @brief Helper function to calculate the diameter of a binary tree.
     *
     * This function computes the height of the tree rooted at the given node
     * and updates the diameter (the longest path between any two nodes in the tree).
     *
     * @param root Pointer to the root node of the binary tree.
     * @param diameter Reference to an integer that stores the diameter of the tree.
     * @return int The height of the tree rooted at the given node.
     */
    int solve(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
            return 0;

        int l = solve(root->left, diameter);
        int r = solve(root->right, diameter);

        diameter = max(diameter, l + r);

        return 1 + max(l, r);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = INT_MIN;
        solve(root, diameter);

        return diameter;
    }
};