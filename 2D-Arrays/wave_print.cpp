#include <bits/stdc++.h> 
/**
 * @brief Generates a wave-like traversal of a 2D array.
 * 
 * This function takes a 2D array and returns a vector containing the elements
 * of the array traversed in a wave-like pattern. In this pattern, the elements
 * of the first column are traversed top to bottom, the second column bottom to top,
 * the third column top to bottom, and so on.
 * 
 * @param arr The 2D array to be traversed.
 * @param nRows The number of rows in the 2D array.
 * @param mCols The number of columns in the 2D array.
 * @return A vector containing the elements of the 2D array in wave-like order.
 */
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{   
    vector<int> result;
    for(int cols = 0; cols < mCols; cols++)
    {
        if(cols & 1)
        {
            for(int rows = nRows - 1; rows >= 0; rows--)
            {
                result.push_back(arr[rows][cols]);
            }
        }
        else
        {
            for(int rows = 0; rows < nRows; rows++)
            {
                result.push_back(arr[rows][cols]);
            }
        }
    }
    return result;
}