// LeetCode 199. Binary Tree Right Side View

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
/**
 * @brief Computes the right side view of a binary tree.
 *
 * This function returns a vector containing the values of the nodes that are visible
 * when the tree is viewed from the right side.
 *
 * @param root A pointer to the root node of the binary tree.
 * @return A vector of integers representing the right side view of the binary tree.
 *
 * The function uses a breadth-first search (BFS) approach to traverse the tree level by level.
 * It maintains a map to store the last node value encountered at each level (line).
 * The map is then used to construct the result vector containing the rightmost node values
 * at each level.
 *
 * If the input tree is empty (root is nullptr), the function returns an empty vector.
 */
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        if (root == nullptr)
            return res;

        map<int, int> mpp;
        //   |     |
        //  line  node

        queue<pair<TreeNode *, int>> q;
        //               |      |
        //             node    line

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode *temp = it.first;
            int line = it.second;

            mpp[line] = temp->val;

            if (temp->left)
                q.push({temp->left, line + 1});
            if (temp->right)
                q.push({temp->right, line + 1});
        }

        for (auto i : mpp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};