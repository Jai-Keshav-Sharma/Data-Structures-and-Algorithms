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
 * @brief Computes the bottom view of a binary tree.
 *
 * This function returns a vector containing the bottom view of the given binary tree.
 * The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.
 *
 * @param root A pointer to the root node of the binary tree.
 * @return A vector of integers representing the bottom view of the binary tree.
 *
 * The function uses a breadth-first search (BFS) approach to traverse the tree level by level.
 * It maintains a map to store the last node at each horizontal distance (line) from the root.
 * The map is updated as the tree is traversed, ensuring that the bottom-most node at each horizontal distance is recorded.
 * Finally, the values from the map are collected into a result vector, which is returned.
 */
vector<int> bottomView(TreeNode<int> *root)
{
    vector<int> res;

    if (root == nullptr)
        return res;

    map<int, int> mpp;
    //   |    |
    //  line  node

    queue<pair<TreeNode<int> *, int>> q;
    //                    |      |
    //                   node   line

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode<int> *temp = it.first;
        int line = it.second;

        // the map keeps updating till the last level
        mpp[line] = temp->data;

        if (temp->left)
            q.push({temp->left, line - 1});

        if (temp->right)
            q.push({temp->right, line + 1});
    }

    // pushing the nodes of last level in to result vector
    for (auto each : mpp)
    {
        res.push_back(each.second);
    }
    return res;
}
