// LeetCode 114. Flatten Binary Tree to Linked List

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
public:
    /**
     * @brief Flattens a binary tree to a linked list in-place.
     *
     * This function takes the root of a binary tree and flattens it into a linked list
     * in-place. The flattened tree should follow the same order as a pre-order traversal.
     *
     * The function works by iterating through the tree and for each node, if it has a left
     * child, it finds the rightmost node in the left subtree (inorder predecessor) and links
     * it to the right subtree of the current node. Then, it moves the left subtree to the right
     * and sets the left pointer to NULL. The process continues until all nodes are processed.
     *
     * @param root The root of the binary tree to be flattened.
     */
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        TreeNode *temp = root;

        while (temp != nullptr)
        {
            if (temp->left)
            {

                // getting inorder predecessor of temp
                TreeNode *predec = temp->left;
                while (predec->right != nullptr)
                    predec = predec->right;

                // linking inorder predecessor of left subtree of temp to right
                // subtree of temp
                predec->right = temp->right;

                // setting left subtree of temp to temp->right
                temp->right = temp->left;

                // setting left pointers to NULL
                temp->left = nullptr;
            }
            // actually its moving the temp node towards left but we are writing
            // temp = temp -> right  bcz we above have set the left subtree of
            // temp as temp->right
            temp = temp->right;
        }
    }
};