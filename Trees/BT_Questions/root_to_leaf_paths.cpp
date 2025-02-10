//LeetCode 257. Binary Tree Paths

#include <bits/stdc++.h>
using namespace std;

// Definition for Binary Tree Node

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
private:
    /**
     * @brief Helper function to find all root-to-leaf paths in a binary tree.
     * 
     * This function traverses the binary tree and collects all paths from the root
     * to the leaf nodes. Each path is stored as a vector of integers, representing
     * the node values along the path.
     * 
     * @param root Pointer to the current node in the binary tree.
     * @param ans Vector to store the current path from the root to the current node.
     * @param res Vector of vectors to store all root-to-leaf paths found in the tree.
     */
    void solve(Node *root, vector<int> &ans, vector<vector<int>> &res)
    {
        if (root == nullptr)
            return;

        ans.push_back(root->data);

        if (!root->left && !root->right)
        {
            res.push_back(ans);
        }
        else
        {
            solve(root->left, ans, res);
            solve(root->right, ans, res);
        }
        ans.pop_back();
    }

public:
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> res;
        vector<int> ans;

        if (root == nullptr)
            return res;

        solve(root, ans, res);
        return res;
    }
};