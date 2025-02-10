// LeetCode 105. Construct Binary Tree from Preorder and Inorder Traversal

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
     * @brief Constructs a binary tree from given preorder and inorder traversal arrays.
     *
     * This function recursively constructs a binary tree using the preorder and inorder traversal arrays.
     * It uses a map to store the indices of inorder elements for quick lookup.
     *
     * @param preorder A vector of integers representing the preorder traversal of the tree.
     * @param preStart The starting index of the current subtree in the preorder array.
     * @param preEnd The ending index of the current subtree in the preorder array.
     * @param inorder A vector of integers representing the inorder traversal of the tree.
     * @param inStart The starting index of the current subtree in the inorder array.
     * @param inEnd The ending index of the current subtree in the inorder array.
     * @param inMap A map that stores the indices of elements in the inorder array for quick lookup.
     * @return A pointer to the root node of the constructed binary tree.
     */
    TreeNode *solve(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd,
                    map<int, int> &inMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder,
                           inStart, inRoot - 1, inMap);

        root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder,
                            inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    /**
     * @brief Builds a binary tree from given preorder and inorder traversal vectors.
     * 
     * This function constructs a binary tree using the preorder and inorder traversal
     * sequences of the tree. It uses a helper function `solve` to recursively build
     * the tree.
     * 
     * @param preorder A vector of integers representing the preorder traversal of the tree.
     * @param inorder A vector of integers representing the inorder traversal of the tree.
     * @return TreeNode* A pointer to the root of the constructed binary tree.
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = solve(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, inMap);

        return root;
    }
};