// LeetCode 542. 01 Matrix

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Updates the matrix such that each cell contains the distance to the nearest cell with a value of 0.
 * 
 * This function takes a 2D matrix of integers as input, where each cell contains either 0 or 1. 
 * It computes and returns a new matrix where each cell contains the shortest distance to the nearest cell with a value of 0.
 * 
 * The function uses a Breadth-First Search (BFS) approach to calculate the distances efficiently.
 * 
 * @param mat A 2D vector of integers representing the input matrix. Each cell contains either 0 or 1.
 * @return A 2D vector of integers where each cell contains the shortest distance to the nearest cell with a value of 0.
 * 
 * @note The input matrix is not modified. The function creates and returns a new matrix with the computed distances.
 * 
 * @example
 * Input: mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}
 * Output: {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}}
 * 
 * @complexity
 * Time Complexity: O(n * m), where n is the number of rows and m is the number of columns in the matrix.
 * Space Complexity: O(n * m) for the visited matrix and the queue used in BFS.
 */
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    //            {{row, col}, distance}
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                visited[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        ans[row][col] = dist;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol])
            {
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, dist + 1});
            }
        }
    }
    return ans;
}