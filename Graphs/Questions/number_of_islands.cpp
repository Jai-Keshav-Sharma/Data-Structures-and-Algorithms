// GeeksForGeeks Practice

#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    bool isValid(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1' && visited[row][col] == 0)
        {
            return true;
        }
        return false;
    }

    /**
     * @brief Performs a Breadth-First Search (BFS) traversal starting from the given cell in the grid.
     *        Marks all connected land cells ('1') as visited.
     * 
     * @param row The starting row index of the BFS traversal.
     * @param col The starting column index of the BFS traversal.
     * @param visited A 2D vector to keep track of visited cells in the grid.
     *                visited[i][j] is 1 if the cell (i, j) has been visited, otherwise 0.
     * @param grid A 2D vector representing the grid of characters ('1' for land, '0' for water).
     *             The grid is used to determine the connectivity of land cells.
     * 
     * @details The function uses a queue to explore all neighboring cells in 8 possible directions
     *          (up, down, left, right, and the 4 diagonals). It ensures that only valid and unvisited
     *          land cells are added to the queue for further exploration.
     * 
     * @note This function assumes the existence of an `isValid` helper function that checks whether
     *       a given cell is within bounds, unvisited, and a land cell ('1').
     */
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            
            // checking for neighbouring islands in all 8 directions arounf the current node
            for (int delRow = -1; delRow <= 1; delRow++)
            {
                for (int delCol = -1; delCol <= 1; delCol++)
                {
                    int neighRow = row + delRow;
                    int neighCol = col + delCol;

                    if (isValid(neighRow, neighCol, visited, grid))
                    {
                        visited[neighRow][neighCol] = 1;
                        q.push({neighRow, neighCol});
                    }
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    /**
     * @brief Counts the number of islands in a given 2D grid.
     * 
     * An island is defined as a group of connected '1's (land) surrounded by '0's (water).
     * The function uses Breadth-First Search (BFS) to traverse and mark visited cells.
     * 
     * @param grid A 2D vector of characters representing the grid, where '1' indicates land
     *             and '0' indicates water.
     * @return int The total number of islands in the grid.
     * 
     * @note The function assumes that the input grid is non-empty and rectangular.
     */
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        int cnt = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    cnt++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return cnt;
    }
};
