// LeetCode 2385. Amount of Time for Binary Tree to Be Infected

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

************************************************************/
template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/**
 * @brief Calculates the minimum time required to burn the entire binary tree starting from a given node.
 *
 * This function uses Breadth-First Search (BFS) to determine the minimum time required to burn the entire binary tree.
 * It first maps each node to its parent node, then performs a BFS starting from the target node to calculate the time.
 *
 * @param root Pointer to the root node of the binary tree.
 * @param start The value of the starting node from which the burning begins.
 * @return int The minimum time required to burn the entire binary tree.
 */
int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    if (root == nullptr)
        return 0;

    // mapping nodes to their parents
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent;
    queue<BinaryTreeNode<int> *> q;

    BinaryTreeNode<int> *target;

    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();

        // storing starting node if found as only its value is given in question
        if (temp->data == start)
            target = temp;

        if (temp->left)
        {
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    } // mapping nodes to their parents done

    // calculating time to burn using BFS
    unordered_map<BinaryTreeNode<int> *, bool> visited;

    q.push(target);
    visited[target] = true;

    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        time++;

        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }

            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }

            if (parent.find(temp) != parent.end() && !visited[parent[temp]])
            {
                q.push(parent[temp]);
                visited[parent[temp]] = true;
            }
        }
    }
    return time - 1;
}
