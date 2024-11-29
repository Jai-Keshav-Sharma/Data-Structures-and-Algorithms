/*
    Approach: first we have to print the first row
                then the last column
                then the last row
                then the first column
                then again the first row

            meanwhile we also have to update the first row, last row, first col and last col indices.
*/

/**
 * @class Solution
 * @brief Provides a method to return the elements of a 2D matrix in spiral order.
 * 
 * This class contains a single public method that takes a 2D vector (matrix) as input
 * and returns a vector containing the elements of the matrix in spiral order.
 */

/**
 * @fn vector<int> spiralOrder(vector<vector<int>> &matrix)
 * @brief Returns the elements of the given 2D matrix in spiral order.
 * 
 * This method traverses the matrix in a spiral order starting from the top-left corner
 * and moving right, down, left, and up, repeatedly until all elements are visited.
 * 
 * @param matrix A reference to a 2D vector of integers representing the matrix.
 * @return A vector of integers containing the elements of the matrix in spiral order.
 * 
 * @note The input matrix is assumed to be non-empty and rectangular (all rows have the same number of columns).
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        // initialising indices
        int firstRow = 0;
        int lastCol = col - 1;
        int lastRow = row - 1;
        int firstCol = 0;

        int count = 0;
        int total = row * col;

        while (count < total)
        {
            // printitng first row
            for (int index = firstCol; count < total && index <= lastCol; index++)
            {
                ans.push_back(matrix[firstRow][index]);
                count++;
            }
            firstRow++;

            // printing last col
            for (int index = firstRow; count < total && index <= lastRow; index++)
            {
                ans.push_back(matrix[index][lastCol]);
                count++;
            }
            lastCol--;

            // printing last row
            for (int index = lastCol; count < total && index >= firstCol; index--)
            {
                ans.push_back(matrix[lastRow][index]);
                count++;
            }
            lastRow--;

            // printing first col
            for (int index = lastRow; count < total && index >= firstRow; index--)
            {
                ans.push_back(matrix[index][firstCol]);
                count++;
            }
            firstCol++;
        }
        return ans;
    }
};