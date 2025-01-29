// LeetCode 124. Binary Tree Maximum Path Sum

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
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
 * @brief Computes the maximum path sum in a binary tree.
 *
 * This function calculates the maximum path sum in a binary tree where the path
 * can start and end at any node. It updates the maximum sum encountered during
 * the traversal of the tree.
 *
 * @param root Pointer to the root node of the binary tree.
 * @param maxSum Reference to an integer that stores the maximum path sum found.
 * @return The maximum path sum for the subtree rooted at the given node.
 */
int solve(TreeNode<int> *root, int &maxSum)
{
    if (root == nullptr)
        return 0;

    int lsum = max(0, solve(root->left, maxSum));

    // if(lsum < 0)
    //     return 0; // causes error cz forcefully returning 0 if lsum or rsum < 0

    int rsum = max(0, solve(root->right, maxSum));

    // if(rsum < 0)
    //     return 0;

    maxSum = max(maxSum, root->val + lsum + rsum);

    return root->val + max(lsum, rsum);
}

// ALITER
int solve(TreeNode<int> *root, int &maxSum)
{
    if (root == nullptr)
        return 0;

    int lsum = solve(root->left, maxSum);
    int rsum = solve(root->right, maxSum);

    if (lsum < 0)
        lsum = 0;
    if (rsum < 0)
        rsum = 0;

    maxSum = max(maxSum, root->val + lsum + rsum);

    return root->val + max(lsum, rsum);
}

int maxPathSum(TreeNode<int> *root)
{
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}