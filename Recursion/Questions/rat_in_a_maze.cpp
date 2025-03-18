#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &visited, int n)
    {
        if (row >= 0 && row < n && col >= 0 && col < n && mat[row][col] != 0 && visited[row][col] == 0)
        {
            return true;
        }
        return false;
    }

    /**
     * @brief Recursive function to find all possible paths in a maze from the top-left corner
     *        to the bottom-right corner.
     * 
     * @param row Current row index in the maze.
     * @param col Current column index in the maze.
     * @param path String representing the current path taken ('D' for down, 'L' for left, 
     *             'R' for right, 'U' for up).
     * @param ans Reference to a vector of strings to store all valid paths from start to end.
     * @param mat Reference to the 2D vector representing the maze (1 for open cell, 0 for blocked cell).
     * @param visited Reference to a 2D vector to track visited cells during the recursion.
     * @param n Size of the maze (n x n).
     * 
     * @note This function uses backtracking to explore all possible paths in the maze. It ensures
     *       that the same cell is not visited more than once in a single path by marking it as 
     *       visited before recursion and unmarking it after recursion.
     * 
     * @pre The function assumes that the maze is a square matrix of size n x n, and the starting 
     *      point (0, 0) and ending point (n-1, n-1) are valid and open cells.
     * 
     * @post All valid paths from the top-left to the bottom-right corner are stored in the `ans` vector.
     */
    void solve(int row, int col, string path, vector<string> &ans, vector<vector<int>> &mat,
               vector<vector<int>> &visited, int n)
    {
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // down
        if (isSafe(row + 1, col, mat, visited, n))
        {
            visited[row][col] = 1;
            solve(row + 1, col, path + 'D', ans, mat, visited, n);
            visited[row][col] = 0;
        }

        // left
        if (isSafe(row, col - 1, mat, visited, n))
        {
            visited[row][col] = 1;
            solve(row, col - 1, path + 'L', ans, mat, visited, n);
            visited[row][col] = 0;
        }

        // right
        if (isSafe(row, col + 1, mat, visited, n))
        {
            visited[row][col] = 1;
            solve(row, col + 1, path + 'R', ans, mat, visited, n);
            visited[row][col] = 0;
        }

        // up
        if (isSafe(row - 1, col, mat, visited, n))
        {
            visited[row][col] = 1;
            solve(row - 1, col, path + 'U', ans, mat, visited, n);
            visited[row][col] = 0;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        if (mat[0][0] == 0)
            return {};

        string path = "";
        vector<string> ans;
        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        solve(0, 0, path, ans, mat, visited, n);
        return ans;
    }
};
