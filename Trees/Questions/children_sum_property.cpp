#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        int data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    /**
     * @brief Checks if a binary tree satisfies the children sum property.
     * 
     * The children sum property states that for every node of the tree, 
     * the node's value must be equal to the sum of its children's values.
     * 
     * @param root Pointer to the root node of the binary tree.
     * @return int Returns 1 if the tree satisfies the children sum property, otherwise returns 0.
     */
    int isSumProperty(Node *root)
    {
        if (root == nullptr || !root->left && !root->right)
            return 1;

        int sum = 0;

        if (root->left)
            sum += root->left->data;
        if (root->right)
            sum += root->right->data;

        return sum == root->data && isSumProperty(root->left) && isSumProperty(root->right);
    }
};