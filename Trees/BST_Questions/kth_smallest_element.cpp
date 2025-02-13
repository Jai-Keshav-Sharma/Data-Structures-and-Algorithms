// LeetCode 230. Kth Smallest Element in a BST

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
     * @brief Finds the k-th smallest element in a Binary Search Tree (BST).
     *
     * This function uses Morris Inorder Traversal to find the k-th smallest element
     * in a BST without using extra space for recursion or a stack.
     *
     * @param root Pointer to the root node of the BST.
     * @param k The k-th position (1-based index) to find the smallest element.
     * @return The value of the k-th smallest element in the BST. If the k-th smallest
     *         element does not exist, returns -1.
     */
    int kthSmallest(TreeNode *root, int k)
    {
        // base case
        if (root == nullptr)
            return -1;

        TreeNode *ans = nullptr;
        int cnt = 0;

        // MORRIS INORDER TRAVERSAL
        TreeNode *curr = root;
        TreeNode *predec = nullptr;

        while (curr)
        {
            // left not exists
            if (!curr->left)
            {
                cnt++;
                if (cnt == k)
                {
                    ans = curr;
                }
                curr = curr->right;
            }
            else
            {
                predec = curr->left;
                while (predec->right != nullptr && predec->right != curr)
                {
                    predec = predec->right;
                }

                if (predec->right == nullptr)
                {
                    predec->right = curr;
                    curr = curr->left;
                }
                else
                {
                    predec->right = nullptr;
                    cnt++;
                    if (cnt == k)
                    {
                        ans = curr;
                    }
                    curr = curr->right;
                }
            }
        } // MORRIS TRAVERSAL END

        // if node is not found return -1;
        return (ans != nullptr) ? ans->val : -1;
    }
};