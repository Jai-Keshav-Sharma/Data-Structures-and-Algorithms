#include <bits/stdc++.h>
using namespace std;

/************************************************************

    Following is the TreeNode class structure:

************************************************************/
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

/**
 * @brief Computes the top view of a binary tree.
 *
 * This function returns a vector containing the top view of the binary tree.
 * The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
 *
 * @param root A pointer to the root node of the binary tree.
 * @return A vector of integers representing the top view of the binary tree.
 *
 * The function uses a map to store the first node at each horizontal distance (line) from the root.
 * It performs a level-order traversal using a queue to ensure nodes are processed in the correct order.
 * Nodes are added to the result vector in ascending order of their horizontal distance.
 */
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> res;

    if (root == nullptr)
        return res;

    // map stores the keys in ascemding order, unlike unordered_map
    map<int, int> mpp;
    //   |     |
    //  line  node

    queue<pair<TreeNode<int> *, int>> q;
    //                   |        |
    //                 node      line

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode<int> *temp = it.first;
        int line = it.second;

        if (mpp.find(line) == mpp.end())
            mpp[line] = temp->data;

        if (temp->left)
            q.push({temp->left, line - 1});

        if (temp->right)
            q.push({temp->right, line + 1});
    }
    for (auto i : mpp)
    {
        res.push_back(i.second);
    }
    return res;
}
