#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    bool isLeaf(Node *root)
    {
        if (!root->left and !root->right)
            return true;
        return false;
    }

    /**
     * @brief Adds the left boundary of the binary tree to the result vector.
     *
     * This function traverses the left boundary of the binary tree starting from the left child of the root node.
     * It adds the data of each non-leaf node encountered during the traversal to the result vector.
     *
     * @param root Pointer to the root node of the binary tree.
     * @param res Reference to the vector that stores the boundary traversal result.
     */
    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;

        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    /**
     * @brief Adds the leaf nodes of a binary tree to the result vector.
     *
     * This function traverses the binary tree starting from the given root node
     * and adds all the leaf nodes to the provided result vector.
     *
     * @param root Pointer to the root node of the binary tree.
     * @param res Reference to the vector where leaf node values will be stored.
     */
    void addLeaves(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }

        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }

    /**
     * @brief Adds the right boundary nodes of a binary tree to the result vector.
     *
     * This function traverses the right boundary of the binary tree starting from the right child of the root node.
     * It collects all the non-leaf nodes in a temporary vector and then appends them in reverse order to the result vector.
     *
     * @param root Pointer to the root node of the binary tree.
     * @param res Reference to the vector where the boundary nodes are to be stored.
     */
    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;

        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }

public:
    /**
     * @brief Performs the boundary traversal of a binary tree.
     * 
     * This function returns a vector containing the boundary nodes of the binary tree
     * in an anti-clockwise direction starting from the root. The boundary includes the 
     * left boundary, leaves, and the right boundary (excluding the root if it is a leaf).
     * 
     * @param root Pointer to the root node of the binary tree.
     * @return vector<int> A vector containing the boundary nodes of the binary tree.
     */
    vector<int> boundaryTraversal(Node *root)
    {

        vector<int> res;

        if (root == nullptr)
            return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};