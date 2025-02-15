#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * @brief Finds the inorder successor of a given node in a Binary Search Tree (BST).
 *
 * This function takes the root of the BST and a target node x, and returns the inorder successor of x.
 * The inorder successor of a node x in a BST is the node with the smallest key greater than x->data.
 *
 * @param root The root node of the BST.
 * @param x The target node whose inorder successor is to be found.
 * @return Node* The inorder successor of the target node x. If no successor exists, returns nullptr.
 */
Node *solve(Node *root, Node *x)
{
    if (root == nullptr || x == nullptr)
        return nullptr;

    Node *succ = root;
    while (root)
    {
        if (root->data <= x->data)
        {
            root = root->right;
        }
        else
        {
            succ = root;
            root = root->left;
        }
    }

    return succ ? succ : nullptr;
}