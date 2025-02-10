// LeetCode 662. Maximum Width of Binary Tree

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
     * @brief Computes the maximum width of a binary tree.
     *
     * The width of a binary tree is the maximum width among all levels. The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return The maximum width of the binary tree.
     *
     * The function uses a level-order traversal (BFS) to traverse the tree. Each node is paired with its index in a hypothetical complete binary tree. The width of each level is calculated using the indices of the first and last nodes at that level.
     */
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int ans = 0;

        queue<pair<TreeNode *, int>> q;
        //             |        |
        //            node    index

        q.push({root, 0});

        while (!q.empty())
        {
            // at any iteration, the size of the queue represents the number of
            // nodes in that level
            int LevelSize = q.size();

            // the first element of each level is q.front() after each iteration
            // of while loop
            int level_min_index = q.front().second;

            // first and last variables to store indices of first and last node
            // to calculate the maximum number of nodes between first and last
            // node at any level by (last - first + 1)
            int first, last;

            // processing current level and getting its width
            for (int i = 0; i < LevelSize; i++)
            {

                // the indices of left and right children of current node is
                // decided by the current index of the current node
                long long int curr_index = q.front().second - level_min_index;

                TreeNode *temp = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr_index;
                if (i == LevelSize - 1)
                    last = curr_index;

                // left child of current node will have index = (2 * curr_index
                // + 1) and right child will have (2 * curr_index + 2)
                if (temp->left)
                    q.push({temp->left, curr_index * 2 + 1});
                if (temp->right)
                    q.push({temp->right, curr_index * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};