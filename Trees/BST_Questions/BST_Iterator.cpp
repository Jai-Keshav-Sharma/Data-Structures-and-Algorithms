// LeetCode 173. Binary Search Tree Iterator

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
class BSTIterator
/**
 * @file BST_Iterator.cpp
 * @brief Implementation of a Binary Search Tree (BST) Iterator using a stack to perform in-order traversal.
 * 
 * This file contains the implementation of a BST Iterator class that allows
 * in-order traversal of a binary search tree using a stack. The iterator
 * provides methods to get the next element in the in-order sequence and to
 * check if there are more elements to be processed.
 * 
 * The approach involves using a stack to simulate the in-order traversal.
 * The pushAll(TreeNode* root) method is used to push all the left elements
 * of the given node into the stack, following the in-order traversal pattern
 * (LEFT -> ROOT -> RIGHT).
 * 
 * The BSTIterator(TreeNode* root) constructor initializes the iterator by
 * pushing all the left elements of the root node into the stack.
 * 
 * The next() method returns the next element in the in-order sequence by
 * popping the top element from the stack and pushing all the left elements
 * of the right child of the popped element into the stack.
 * 
 * The hasNext() method checks if there are more elements to be processed
 * by checking if the stack is not empty.
 * 
 * @class BSTIterator
 * @brief Iterator for in-order traversal of a binary search tree.
 * 
 * @private
 * @var std::stack<TreeNode*> st
 * Stack to store the nodes for in-order traversal.
 * 
 * @private
 * @fn void pushAll(TreeNode* root)
 * Pushes all the left elements of the given node into the stack.
 * 
 * @public
 * @fn BSTIterator(TreeNode* root)
 * Constructor that initializes the iterator by pushing all the left elements
 * of the root node into the stack.
 * 
 * @public
 * @fn int next()
 * Returns the next element in the in-order sequence.
 * 
 * @public
 * @fn bool hasNext()
 * Checks if there are more elements to be processed.
 */
{
private:
    // approach : we will be using the inorder treaversal but with the help of
    // stack.
    // using pushALL(node), we push all the left elemets of the node
    // into the stack as in Inorder, the fashion in LEFT>ROOT>RIGHT.

    stack<TreeNode *> st;

    void pushAll(TreeNode *root)
    {
        if (root == nullptr)
            return;

        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root) { pushAll(root); }

    // when we call next(), we return the top of stack as its the next element
    // in inorder and before popping,  we call pushAll(node -> right) when
    // popping, it means that we have processed that node and acc to Inorder, we
    // shall now head towards to the right part of node. thats why we call
    // pushAll(node -> right) so that we can again start the inorder traversal
    // for right of the node

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);

        return temp->val;
    }

    // at any instance, if stack is not empty, it means that we definitely have
    // a next element
    bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */