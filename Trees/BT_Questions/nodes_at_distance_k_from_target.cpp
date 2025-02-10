// LeetCode 863. All Nodes Distance K in Binary Tree

#include <bits/stdc++.h>
using namespace std;

/*************************************************************

    Following is the Binary Tree node structure for reference:

*************************************************************/
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
 * @brief Marks the parent nodes for each node in the binary tree.
 * 
 * This function traverses the binary tree starting from the root node and 
 * records the parent of each node in the provided unordered_map. The parent 
 * map will have child nodes as keys and their corresponding parent nodes as values.
 * 
 * @param root Pointer to the root node of the binary tree.
 * @param parent Reference to an unordered_map that will store the parent-child relationships.
 */
void markParents(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();

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
    }
}

/**
 * @brief Finds all nodes at a distance K from the target node in a binary tree.
 * 
 * This function takes a binary tree root node, a target node, and a distance K,
 * and returns a vector of pointers to nodes that are exactly K distance away from the target node.
 * 
 * @param root The root node of the binary tree.
 * @param target The target node from which the distance is measured.
 * @param K The distance from the target node.
 * @return vector<BinaryTreeNode<int> *> A vector of pointers to nodes that are K distance away from the target node.
 * 
 * The function uses a breadth-first search (BFS) approach to traverse the tree and find nodes at the specified distance.
 * It also uses an unordered_map to keep track of parent nodes for each node to facilitate traversal in all directions.
 * 
 * Example usage:
 * @code
 * BinaryTreeNode<int> *root = ...; // Assume this is initialized
 * BinaryTreeNode<int> *target = ...; // Assume this is initialized
 * int K = 2;
 * vector<BinaryTreeNode<int> *> result = printNodesAtDistanceK(root, target, K);
 * @endcode
 */
vector<BinaryTreeNode<int> *> printNodesAtDistanceK(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target, int K)
{
    vector<BinaryTreeNode<int> *> res;

    if (root == nullptr)
        return res;

    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent;

    markParents(root, parent);

    int level = 0;
    queue<BinaryTreeNode<int> *> q;
    unordered_map<BinaryTreeNode<int> *, bool> visited;

    q.push(target);
    visited[target] = true;

    while (!q.empty())
    {
        int size = q.size();
        if (level == K)
            break;
        else
            level++;

        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (parent.find(curr) != parent.end() && !visited[parent[curr]])
            {
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
    }

    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();

        res.push_back(temp);
    }
    return res;
}