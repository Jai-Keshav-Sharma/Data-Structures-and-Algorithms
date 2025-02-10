#include <bits/stdc++.h>
using namespace std;

/*************************************************************

    Following is the Binary Tree node structure

*************************************************************/
template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/**
 * @brief Modifies the given binary tree such that every node's value becomes the sum of its children's values.
 * 
 * This function changes the tree in a way that for every node, if the sum of its children's values is greater than 
 * the node's value, the node's value is updated to this sum. Otherwise, the children's values are updated to the node's value.
 * During the backtracking phase, the node's value is updated to the sum of its children's values.
 * 
 * @param root Pointer to the root node of the binary tree.
 */
void changeTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return;

    int sum = 0;

    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;

    // if root has value greater than sum of its children values, then assign the value of root to the children
    if (sum > root->data)
        root->data = sum;
    // else assign the value of sum to the root
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    // backtracking
    int tot = 0;

    // while backtracking, replace the value of root nodes by the sum of its children
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;

    // replace only if current node is not a leaf node
    if (root->left || root->right)
        root->data = tot;
}