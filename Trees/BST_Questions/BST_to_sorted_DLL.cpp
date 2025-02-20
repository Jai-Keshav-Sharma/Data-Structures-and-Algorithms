#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the TreeNode class structure

    ************************************************************/
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
 * @brief Converts a Binary Search Tree (BST) to a sorted Doubly Linked List (DLL).
 * 
 * This function performs an in-order traversal of the BST and links the nodes 
 * to form a sorted doubly linked list. The left pointer of each node in the BST 
 * is used as the previous pointer in the DLL, and the right pointer is used as 
 * the next pointer in the DLL.
 * 
 * @param root Pointer to the root node of the BST.
 * @param prev Reference to the pointer that keeps track of the previous node 
 *             in the DLL during the in-order traversal.
 * @param headOfList Reference to the pointer that will point to the head of 
 *                   the resulting sorted DLL.
 */
void convert(TreeNode<int> *root, TreeNode<int> *&prev, TreeNode<int> *&headOfList)
{
    if (root == nullptr)
        return;

    // going left
    convert(root->left, prev, headOfList);

    // processing
    if (prev == nullptr)
    {
        headOfList = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    // going right
    convert(root->right, prev, headOfList);
}

TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    if (root == nullptr)
        return root;

    TreeNode<int> *prev = nullptr;
    TreeNode<int> *headOfList = nullptr;

    convert(root, prev, headOfList);
    if (prev)
        prev->right = nullptr;
    if (headOfList)
        headOfList->left = nullptr;

    return headOfList;
}