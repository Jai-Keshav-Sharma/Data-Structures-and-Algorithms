// LeetCode 653. Two Sum IV - Input is a BST


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
class BSTiterator
{
private:
    stack<TreeNode *> st;
    bool reverse = true;

    // reverse = true ----> RIGHT > ROOT > LEFT (INORDER)
    // reverse = false ---> LEFT > ROOT > RIGHT (INORDER REVERSED)

    void pushAll(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            if (reverse)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
    }

public:
    BSTiterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        if (reverse)
        {
            pushAll(temp->left);
        }
        else
        {
            pushAll(temp->right);
        }

        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
};

class Solution
{
public:
    /**
     * @brief Finds if there exist two elements in the BST such that their sum is equal to a given target.
     * 
     * This function uses two iterators to traverse the BST in both inorder (ascending) and reverse inorder (descending) manner.
     * It then checks if there exist two elements whose sum equals the target value.
     * 
     * @param root Pointer to the root node of the BST.
     * @param k The target sum value.
     * @return true If there exist two elements in the BST whose sum equals the target value.
     * @return false If no such elements exist.
     */
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        ;

        BSTiterator l(root, false); // stack of this instance will store
                                    // elements in inorder manner (ascending)
        BSTiterator r(root, true);  // stack of this instance will store elements
                                    // in reverse inorder manner (descending)

        int i = l.next(); // first element in inorder traversal
        int j = r.next(); // last element in inorder traversal

        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = l.next(); // moving forward from first element
            }
            else
            {
                j = r.next(); // moving backwards from last element
            }
        }
        return false;
    }
};

// to know more about BST Iterator class, goto LeetCode 173.