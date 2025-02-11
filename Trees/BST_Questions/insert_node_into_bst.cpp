// LeetCode 701. Insert into a Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the TreeNode class structure

    ************************************************************/
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
};

/**
 * @brief Inserts a new node with a given value into a Binary Search Tree (BST).
 *
 * This function takes the root of a BST and a value to be inserted. It inserts
 * the value into the appropriate position in the BST while maintaining the BST
 * property. If the root is nullptr, it creates a new node with the given value
 * and returns it as the new root.
 *
 * @param root Pointer to the root node of the BST.
 * @param val The value to be inserted into the BST.
 * @return TreeNode<int>* Pointer to the root node of the BST after insertion.
 */
TreeNode<int> *insertionInBST(TreeNode<int> *root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return root;
    }

    TreeNode<int> *temp = root;
    while (temp)
    {
        if (temp->val < val)
        {
            if (temp->right != nullptr)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (temp->left != nullptr)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}