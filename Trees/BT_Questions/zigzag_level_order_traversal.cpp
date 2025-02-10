// Leetcode 103: Binary Tree Zigzag Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    /**
     * @brief Performs a zigzag level order traversal of a binary tree.
     *
     * This function takes the root of a binary tree and returns a vector of vectors,
     * where each inner vector contains the values of the tree nodes at each level.
     * The traversal alternates between left-to-right and right-to-left at each level.
     *
     * @param root A pointer to the root node of the binary tree.
     * @return A vector of vectors containing the zigzag level order traversal of the tree.
     *         Each inner vector represents the nodes at a particular level.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // vector to store the final zigzag traversal
        vector<vector<int>> result;

        // if tree is empty, return result which is also empty till now
        if (!root)
            return result;

        // queue to store nodes
        queue<TreeNode *> q;

        // to keep track of wahether we have to traverse L to R or R to L at any
        // level
        bool leftToRight = true;

        // pushing root in the queue
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            // vector to store nodes of a single level of tree
            vector<int> row(size);

            // pushing all the nodes present at a level into the row vector
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                // if leftToRight = T then the value is to be pushed in L to R
                // and R to L otherwise
                int index = leftToRight ? i : size - 1 - i;

                // pushing the value into the row vector
                row[index] = temp->val;

                // pushing the left and right children of the current node into
                // the queue if any
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            // pushing the row veector into the final result vector
            result.push_back(row);
            // changing the direction of insertion
            leftToRight = !leftToRight;
        }
        return result;
    }
};