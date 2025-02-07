// LeetCode 297. Serialize and Deserialize Binary Tree

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    /**
     * @brief Serializes a binary tree to a single string.
     *
     * This function takes the root of a binary tree and converts it into a string
     * representation using level-order traversal. Each node's value is appended
     * to the result string followed by a comma. Null nodes are represented by "#,".
     *
     * @param root The root node of the binary tree.
     * @return A string representing the serialized binary tree.
     */
    string serialize(TreeNode *root)
    {
        string res = "";

        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == nullptr)
                res.append("#,");
            else
                res.append(to_string(temp->val) + ',');

            // irrespective of whether the left or right child is NULL or not,
            // we r pushing it into the queue
            if (temp != nullptr)
            { // to make sure that we r not pushing left
              // and right children of a leaf node
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    /**
     * @brief Deserializes a string representation of a binary tree into a TreeNode structure.
     *
     * This function takes a string that represents a serialized binary tree and reconstructs
     * the binary tree from it. The string is expected to be in level-order traversal format,
     * with nodes separated by commas. A '#' character represents a null node.
     *
     * @param data The string representation of the serialized binary tree.
     * @return TreeNode* The root node of the deserialized binary tree. Returns nullptr if the input string is empty.
     */
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr;

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            // creating left node
            getline(s, str, ',');

            if (str == "#")
                temp->left = nullptr;
            else
            {
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }

            // creating right node
            getline(s, str, ',');

            if (str == "#")
                temp->right = nullptr;
            else
            {
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));