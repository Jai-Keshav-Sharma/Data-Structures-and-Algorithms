// LeetCode 994. Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Determines the minimum time required to rot all fresh oranges in a grid.
 * 
 * The function simulates the process of rotting oranges in a grid where:
 * - 0 represents an empty cell.
 * - 1 represents a fresh orange.
 * - 2 represents a rotten orange.
 * 
 * A rotten orange can rot adjacent fresh oranges (up, down, left, right) in one unit of time.
 * The function uses a breadth-first search (BFS) approach to calculate the time required
 * to rot all fresh oranges. If it is not possible to rot all fresh oranges, the function
 * returns -1.
 * 
 * @param grid A 2D vector representing the grid of oranges.
 * @return int The minimum time required to rot all fresh oranges, or -1 if not all fresh
 * oranges can be rotted.
 * 
 * @note The function assumes that the grid is non-empty and contains at least one cell.
 */
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    // { { row, col }, time }
    queue<pair<pair<int, int>, int>> q;

    int cntFresh = 0; // count of all fresh oranges initially

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                visited[i][j] = 2;
                q.push({{i, j}, 0});
            }
            if (grid[i][j] == 1)
            {
                cntFresh++;
            }
        }
    }

    int t = 0;
    int cnt = 0; // to count oranges getting rotten
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int _time = q.front().second;

        q.pop();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, _time + 1});
                cnt++;
            }
        }
        t = _time;
    }

    // if number of fresh oranges at the beginning  != no. of oranges
    // getting rotten, return -1 (all the fresh oranges not got rot)
    return cntFresh == cnt ? t : -1;
}