
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node
 */

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
public:
    /**
     * @brief Computes the left view of a binary tree.
     * 
     * The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
     * This function uses a level-order traversal (BFS) to capture the first node at each level.
     * 
     * @param root Pointer to the root node of the binary tree.
     * @return A vector containing the node values that form the left view of the tree.
     */
    vector<int> leftView(Node *root)
    {
        vector<int> res;

        if (root == nullptr)
            return res;

        map<int, int> mpp;
        //   |     |
        //  line  node

        queue<pair<Node *, int>> q;
        //           |      |
        //          node    line

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *temp = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end())
                mpp[line] = temp->data;

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