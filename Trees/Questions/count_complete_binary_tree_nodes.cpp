// LeetCode 222. Count Complete Tree Nodes

// count number of nodes in a Complete BT in time complexity less than O(N).

#include <bits/stdc++.h>
using namespace std;

/************************************************************

Following is the Binary Tree node class
************************************************************/

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

int leftHeight(TreeNode<int> *root)
{

    TreeNode<int> *node = root;
    int count = 0;

    while (node)
    {
        count++;
        node = node->left;
    }
    return count;
}

int rightHeight(TreeNode<int> *root)
{

    TreeNode<int> *node = root;
    int count = 0;

    while (node)
    {
        count++;
        node = node->right;
    }
    return count;
}

/**
 * @brief Counts the number of nodes in a complete binary tree.
 *
 * This function calculates the total number of nodes in a complete binary tree
 * by leveraging the properties of complete binary trees. If the left and right
 * subtree heights are equal, it means the subtree is a perfect binary tree and
 * the number of nodes can be calculated directly using the formula (2^height - 1).
 * Otherwise, it recursively counts the nodes in the left and right subtrees.
 *
 * @param root Pointer to the root node of the binary tree.
 * @return int The total number of nodes in the binary tree.
 */
int countNodes(TreeNode<int> *root)
{
    if (root == nullptr)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    // left height == right hight means that the current node is forming a complete binary tree
    // for a complete binary tree, total # of nodes is (2^height - 1)
    if (lh == rh)
        return (1 << lh) - 1;

    // else add that node and check for its left and right nodes whether they form a complete BT or not !
    return 1 + countNodes(root->left) + countNodes(root->right);
}