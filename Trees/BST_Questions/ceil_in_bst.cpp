#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the TreeNode class structure:

    ************************************************************/
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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

/**
 * @brief Finds the ceil value in a Binary Search Tree (BST) for a given integer.
 * 
 * The ceil value of a given integer x in a BST is the smallest integer in the BST
 * that is greater than or equal to x.
 * 
 * @param node Pointer to the root node of the BST.
 * @param x The integer value for which the ceil is to be found.
 * @return int The ceil value if it exists, otherwise -1.
 */
int findCeil(BinaryTreeNode<int> *node, int x)
{

    int ceil = -1;

    while (node)
    {
        if (node->data == x)
        {
            ceil = node->data;
            return ceil;
        }

        // moving towards right
        if (x > node->data)
            node = node->right;
        else
        { // moving towards left, if x is less than node -> data, then
          // node -> data is a possile ceil value.
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}