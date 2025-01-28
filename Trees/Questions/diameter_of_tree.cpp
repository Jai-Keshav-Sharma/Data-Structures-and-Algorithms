#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/**
 * @brief Computes the diameter of the binary tree.
 *
 * This function calculates the diameter of a binary tree, which is the length
 * of the longest path between any two nodes in the tree. The path may or may
 * not pass through the root.
 *
 * @param root Pointer to the root node of the binary tree.
 * @param res Reference to an integer that stores the result (diameter) of the tree.
 * @return The height of the current node.
 */
int solve(TreeNode<int> *root, int &res)
{
    if (root == nullptr)
        return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);

    int res = max(res, ans);

    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int res = 0;
    solve(root, res);

    // number of nodes in between two farthest nodes is stored in res
    // but we have been asked to return the number of edges in between
    // thats why (res - 1) is returned

    return res - 1;
}
