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
    TreeNode *minValue(TreeNode *root)
    {
        TreeNode *temp = root;

        while (temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == key)
        {
            // 0 children
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            // 1 child(left)
            if (root->left && !root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // 1 child(right)
            if (root->right && !root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // 2 children
            if (root->left && root->right)
            {
                int mini = minValue(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};