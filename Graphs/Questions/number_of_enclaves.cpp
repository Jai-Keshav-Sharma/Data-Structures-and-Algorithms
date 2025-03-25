// LeetCode 1020. Number of Enclaves

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited,
             vector<vector<int>> &grid, int delrow[], int delcol[])
    {

        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, visited, grid, delrow, delcol);
            }
        }
    }

public:
    /**
     * @brief Calculates the number of enclaves in a grid.
     * 
     * An enclave is defined as a group of 1s (land cells) in the grid that are 
     * completely surrounded by 0s (water cells) and are not connected to the 
     * boundary of the grid. This function uses Depth First Search (DFS) to 
     * traverse the grid and mark all land cells connected to the boundary as 
     * visited. It then counts the remaining unvisited land cells, which are 
     * the enclaves.
     * 
     * @param grid A 2D vector representing the grid, where 1 indicates land 
     *             and 0 indicates water.
     * @return int The number of enclaves in the grid.
     * 
     * @note The function assumes that the grid is non-empty and rectangular.
     * 
     * @details
     * - The function first initializes a visited matrix to keep track of 
     *   visited cells.
     * - It then iterates over the first and last rows, as well as the first 
     *   and last columns, to mark all boundary-connected land cells as visited 
     *   using DFS.
     * - Finally, it traverses the entire grid to count the number of unvisited 
     *   land cells, which represent the enclaves.
     * 
     * @complexity
     * - Time Complexity: O(n * m), where n is the number of rows and m is the 
     *   number of columns in the grid. Each cell is visited at most once.
     * - Space Complexity: O(n * m) for the visited matrix and the recursion 
     *   stack in DFS.
     */
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // first and last row
        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] && grid[0][j] == 1)
            {
                dfs(0, j, visited, grid, delrow, delcol);
            }
            // last row
            if (!visited[n - 1][j] && grid[n - 1][j] == 1)
            {
                dfs(n - 1, j, visited, grid, delrow, delcol);
            }
        }

        // first and last col
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] && grid[i][0] == 1)
            {
                dfs(i, 0, visited, grid, delrow, delcol);
            }
            // last col
            if (!visited[i][m - 1] && grid[i][m - 1] == 1)
            {
                dfs(i, m - 1, visited, grid, delrow, delcol);
            }
        }

        // traversing and counting enclaves
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};