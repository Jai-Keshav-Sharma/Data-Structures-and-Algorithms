// LeetCode 130. Surrounded Regions

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited,
             vector<vector<char>> &mat, int delrow[], int delcol[])
    {
        int n = mat.size();
        int m = mat[0].size();

        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                visited[nrow][ncol] == 0 && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, visited, mat, delrow, delcol);
            }
        }
    }

public:
    /**
     * @brief Solves the "Surrounded Regions" problem by modifying the given board in-place.
     *        The function identifies all 'O' regions that are completely surrounded by 'X'
     *        and replaces them with 'X'. Regions connected to the border are not replaced.
     *
     * @param board A 2D vector of characters representing the board. Each cell contains
     *              either 'X' or 'O'.
     *
     * @details The algorithm works as follows:
     *          1. Traverse the first and last rows of the board to find 'O' cells and
     *             perform a depth-first search (DFS) to mark all connected 'O' cells as visited.
     *          2. Traverse the first and last columns of the board to find 'O' cells and
     *             perform a DFS to mark all connected 'O' cells as visited.
     *          3. Traverse the entire board and replace all unvisited 'O' cells with 'X',
     *             as they are surrounded by 'X'. The visited 'O' cells remain unchanged.
     *
     * @note The function assumes that the input board is non-empty and has at least one row and column.
     */
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // getting O's from first and last row
        for (int j = 0; j < m; j++)
        {
            // first row
            if (board[0][j] == 'O' && !visited[0][j])
            {
                dfs(0, j, visited, board, delrow, delcol);
            }
            // last row
            if (board[n - 1][j] == 'O' && !visited[n - 1][j])
            {
                dfs(n - 1, j, visited, board, delrow, delcol);
            }
        }

        // getting O's from first and last column
        for (int i = 0; i < n; i++)
        {
            // first col
            if (board[i][0] == 'O' && !visited[i][0])
            {
                dfs(i, 0, visited, board, delrow, delcol);
            }
            // last col
            if (board[i][m - 1] == 'O' && !visited[i][m - 1])
            {
                dfs(i, m - 1, visited, board, delrow, delcol);
            }
        }

        // traversing and replacing unvisited O's with X
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};