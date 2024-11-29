//leetcode-74
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 
*/

class Solution {
public:
    /**
     * @brief Searches for a target value in a 2D matrix.
     *
     * This function performs a binary search on a 2D matrix to determine if a target value exists within the matrix.
     * The matrix is assumed to be sorted in ascending order both row-wise and column-wise.
     *
     * @param matrix A reference to a 2D vector of integers representing the matrix.
     * @param target An integer representing the value to search for in the matrix.
     * @return A boolean value indicating whether the target value exists in the matrix (true) or not (false).
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = (row * col) - 1;
        int mid = s + (e - s) / 2;

        while(s <= e)
        {
            int element = matrix[mid / col][mid % col];

            if(element == target)
            {
                return true;
            }
            if(element < target)
            {
                s  = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return false;
    }
};