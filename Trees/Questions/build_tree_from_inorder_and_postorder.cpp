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
     * @brief Constructs a binary tree from inorder and postorder traversal arrays.
     *
     * This function recursively constructs a binary tree using the given inorder
     * and postorder traversal arrays. It uses a hashmap to store the indices of
     * inorder elements for quick lookup.
     *
     * @param inorder A vector of integers representing the inorder traversal of the tree.
     * @param inStart The starting index of the current subtree in the inorder array.
     * @param inEnd The ending index of the current subtree in the inorder array.
     * @param postorder A vector of integers representing the postorder traversal of the tree.
     * @param postStart The starting index of the current subtree in the postorder array.
     * @param postEnd The ending index of the current subtree in the postorder array.
     * @param inMap An unordered_map that maps values to their indices in the inorder array.
     * @return A pointer to the root node of the constructed binary tree.
     */
    TreeNode *solve(vector<int> &inorder, int inStart, int inEnd,
                    vector<int> &postorder, int postStart, int postEnd,
                    unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsOnLeft = inRoot - inStart;

        root->left = solve(inorder, inStart, inRoot - 1, postorder, postStart,
                           postStart + numsOnLeft - 1, inMap);
        root->right = solve(inorder, inRoot + 1, inEnd, postorder,
                            postStart + numsOnLeft, postEnd - 1, inMap);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = solve(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, inMap);

        return root;
    }
};