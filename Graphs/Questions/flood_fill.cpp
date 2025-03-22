// LeetCode 733. Flood Fill

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Performs a Depth-First Search (DFS) to fill connected components in an image.
     * 
     * This function is used in the flood fill algorithm to traverse and update
     * all connected pixels in an image that have the same initial color as the
     * starting pixel. It updates the connected pixels with a new color.
     * 
     * @param row The current row index of the pixel being processed.
     * @param col The current column index of the pixel being processed.
     * @param image A 2D vector representing the original image.
     * @param ans A 2D vector representing the updated image after flood fill.
     * @param newCol The new color to be applied to the connected components.
     * @param iniCol The initial color of the starting pixel.
     * @param visited A 2D vector to track visited pixels during the DFS traversal.
     * @param m The total number of rows in the image.
     * @param n The total number of columns in the image.
     */
    void dfs(int row, int col, vector<vector<int>> &image,
             vector<vector<int>> &ans, int newCol, int iniCol,
             vector<vector<int>> &visited, int m, int n)
    {
        visited[row][col] = 1;
        ans[row][col] = newCol;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int neighRow = row + delRow[i];
            int neighCol = col + delCol[i];

            if (neighRow >= 0 && neighRow < m && neighCol >= 0 &&
                neighCol < n && visited[neighRow][neighCol] == 0 &&
                image[neighRow][neighCol] == iniCol)
            {
                dfs(neighRow, neighCol, image, ans, newCol, iniCol, visited, m,
                    n);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> ans = image;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int iniCol = image[sr][sc];

        dfs(sr, sc, image, ans, color, iniCol, visited, m, n);
        return ans;
    }
};