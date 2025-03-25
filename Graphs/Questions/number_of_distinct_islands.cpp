#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &v, int baseRow, int baseCol)
    {
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;
        v.push_back({row - baseRow, col - baseCol});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, visited, grid, v, baseRow, baseCol);
            }
        }
    }

public:
    /**
     * @brief Counts the number of distinct islands in a 2D grid.
     * 
     * This function takes a 2D grid of integers where '1' represents land and '0' represents water.
     * It identifies and counts the number of distinct islands in the grid. An island is defined as
     * a group of connected '1's (connected horizontally or vertically). Two islands are considered
     * distinct if their shapes are different, even if they are located in different parts of the grid.
     * 
     * @param grid A 2D vector of integers representing the grid.
     *             - grid[i][j] = 1 indicates land.
     *             - grid[i][j] = 0 indicates water.
     * 
     * @return int The number of distinct islands in the grid.
     * 
     * @note The function uses Depth First Search (DFS) to traverse the grid and identify islands.
     *       It keeps track of visited cells to avoid redundant processing. The relative shape of
     *       each island is stored in a set to ensure uniqueness.
     */
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, visited, grid, v, i, j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};