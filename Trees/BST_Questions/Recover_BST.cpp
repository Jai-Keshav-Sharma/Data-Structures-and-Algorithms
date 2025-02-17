// LeetCode 99. Recover Binary Search Tree

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
    TreeNode *first;  // ro store the first violation of inorder
    TreeNode *middle; // to store the element next to first (needed in case if
                      // there is no second violation)
    TreeNode *last;   // to stoire the last violation
    TreeNode *prev;   // to store the prev node

public:
    /**
     * @brief Performs an inorder traversal of a binary search tree (BST) to identify nodes that violate the BST property.
     * 
     * This function traverses the BST in an inorder manner (left-root-right) and checks for violations where a node's value
     * is less than the value of the previous node visited. It identifies up to two such violations:
     * - The first violation is stored in the 'first' and 'middle' pointers.
     * - The second violation (if any) is stored in the 'last' pointer.
     * 
     * @param root Pointer to the root node of the BST.
     */
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        // left recursive call
        inorder(root->left);

        // if prev is greater than current node's value, its a violation
        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
            { // if its first violation
                first = prev;
                middle = root;
            }
            else
            { // if its second violation (no middle needed)
                last = root;
            }
        }
        else
        { // store node into prev if everything is normal
            prev = root;
        }

        // right recursive call
        inorder(root->right);
    }

    /**
     * @brief Recovers a binary search tree (BST) where two nodes have been swapped by mistake.
     * 
     * This function identifies the two nodes that have been swapped in the BST and swaps them back to restore the BST property.
     * It uses an in-order traversal to detect the swapped nodes.
     * 
     * @param root The root node of the binary search tree.
     * 
     * The function handles two cases:
     * 1. If there are two non-adjacent nodes that have been swapped, it swaps the values of the first and last nodes.
     * 2. If there are two adjacent nodes that have been swapped, it swaps the values of the first and middle nodes.
     */
    void recoverTree(TreeNode *root)
    {
        if (root == nullptr)
            return;

        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        // if we have both first and second violation, swap first and last ->
        // vals.
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle) // if there is no last violation, then middle
                                  // is the last violation
            swap(first->val, middle->val);
    }
};