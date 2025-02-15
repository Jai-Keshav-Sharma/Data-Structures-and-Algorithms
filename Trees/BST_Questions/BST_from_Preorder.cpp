// LeetCode 1008.


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
    TreeNode() : val(0), left(nullptr), right(nullptr){}  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                 right(right) {}
};

class Solution
{
public:
    /**
     * @brief Constructs a Binary Search Tree (BST) from a given preorder traversal.
     * 
     * This function recursively constructs a BST from the given preorder traversal
     * vector. It uses the current index and a bound to determine the placement of
     * nodes in the tree.
     * 
     * @param preorder A vector of integers representing the preorder traversal of the BST.
     * @param i A reference to the current index in the preorder vector.
     * @param bound An integer representing the upper bound for the current subtree.
     * @return TreeNode* A pointer to the root of the constructed BST or nullptr if the subtree is empty.
     */
    TreeNode *solve(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, i, root->val);
        root->right = solve(preorder, i, bound);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        // approach :
        //    like we did in the Validate a BST problem where we set lower and
        //    upper bounds for a node and its children must be b/w these bounds
        // here we also use same approach but we use only upper bounds,
        // initially set to INT_MAX.

        // while moving towards root -> left, we set the upper bound to root ->
        // val for the immediate left child of root while moving towards root ->
        // right, the bound for the immediate child is same as the bound for the
        // root node

        // if i goes out of bounds or if value is greater than bound Value for
        // any node, we return null.

        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
};