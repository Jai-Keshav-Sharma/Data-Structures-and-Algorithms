#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    /**
     * @brief Construct a new Node object
     * 
     * @param data The value to be stored in the node
     * @param row The row index of the element in the 2D array
     * @param col The column index of the element in the 2D array
     */
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    /**
     * @brief Merges K sorted arrays into a single sorted array.
     * 
     * This function takes a vector of K sorted arrays and merges them into a single sorted array using a min-heap.
     * 
     * @param arr A vector of vectors, where each inner vector represents a sorted array.
     * @param K The number of sorted arrays.
     * @return A vector containing all elements from the K sorted arrays, merged into a single sorted array.
     */
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node *, vector<Node *>, compare> minh;

        // filling the min-heap with nodes containing first elements of every array
        for (int i = 0; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i][0], i, 0);

            minh.push(temp);
        }

        vector<int> ans;

        // merging
        while (!minh.empty())
        {
            // extracting the minimum element ans pushing into answer
            Node *temp = minh.top();
            ans.push_back(temp->data);
            minh.pop();

            int row = temp->row; // row of current element
            int col = temp->col; // col of current element

            // if the current array has next element
            if (col + 1 < arr[row].size())
            {
                Node *nxt = new Node(arr[row][col + 1], row, col + 1);
                minh.push(nxt);
            }
        }

        return ans;
    }
};