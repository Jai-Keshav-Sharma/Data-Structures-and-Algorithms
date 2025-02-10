#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
/*
 */
template <typename T = int>
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
/**
 * @brief Finds the path from the root node to the given node x in a binary tree.
 * 
 * This function searches for the node with value x in the binary tree rooted at 'root'.
 * If the node is found, it populates the vector 'res' with the path from the root to the node.
 * 
 * @param root Pointer to the root node of the binary tree.
 * @param x The value of the node to be searched.
 * @param res Reference to a vector that will store the path from the root to the node with value x.
 * @return true If the node with value x is found in the binary tree.
 * @return false If the node with value x is not found in the binary tree.
 */
bool solve(TreeNode<int> *root, int x, vector<int> &res)
{
    if (root == nullptr)
        return false;

    res.push_back(root->data);

    // if we have found the desired node, no need to explore further, just return true feom there itself
    if (root->data == x)
        return true;

    // if current node is getting true either from left or right, then there is a possibility that
    // this node may be part of the solution
    if (solve(root->left, x, res) || solve(root->right, x, res))
        return true;

    // if left and right both returning false, then remove the current node from the result
    // as it isn't a part of the solution
    res.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res;

    if (root == nullptr)
        return res;

    solve(root, x, res);
    return res;
}
