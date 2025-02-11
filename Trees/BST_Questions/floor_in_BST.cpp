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
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

/**
 * @brief Finds the floor value in a Binary Search Tree (BST) for a given integer X.
 *
 * The floor value of X in a BST is the greatest value in the BST that is less than or equal to X.
 *
 * @param root Pointer to the root node of the BST.
 * @param X The integer value for which the floor value is to be found.
 * @return The floor value of X in the BST. If no such value exists, returns -1.
 */
int floorInBST(TreeNode<int> *root, int X)
{
    if (root == nullptr)
        return -1;

    int ans = -1;

    while (root)
    {
        if (root->val == X)
        {
            ans = X;
            return ans;
        }
        else if (root->val > X)
        {
            root = root->left;
        }
        else
        {
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}