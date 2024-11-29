/**
 * @file II-binary_search.cpp
 * @brief Leetcode - 240: Search a 2D Matrix II
 * 
 * This file contains the implementation of an efficient algorithm to search for a value target in an m x n integer matrix.
 * The matrix has the following properties:
 * - Integers in each row are sorted in ascending order from left to right.
 * - Integers in each column are sorted in ascending order from top to bottom.
 * 
 * The algorithm starts from the top-right corner of the matrix and iteratively narrows down the search space by moving
 * either left or down based on the comparison of the current element with the target.
 * 
 * @class Solution
 * @brief Contains the method to search for the target value in the matrix.
 * 
 * @method bool searchMatrix(vector<vector<int>>& matrix, int target)
 * @param matrix A 2D vector of integers representing the matrix.
 * @param target An integer value to search for in the matrix.
 * @return Returns true if the target is found in the matrix, otherwise returns false.
 */




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowInd = 0;
        int colInd = col - 1;

        while(rowInd < row and colInd >= 0)
        {
            int element = matrix[rowInd][colInd];

            if(element == target)
            {
                return true;
            }
            if(element < target)
            {
                rowInd++;
            }
            else
            {
                colInd--;
            }
        }
        return false;
    }
};