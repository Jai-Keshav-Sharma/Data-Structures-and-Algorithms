/**
 * @file rat-in-a-maze.cpp
 * @brief Solution to the Rat in a Maze problem using recursion and backtracking.
 * 
 * This file contains the implementation of the Rat in a Maze problem, where the goal is to find all possible paths 
 * for a rat to move from the top-left corner to the bottom-right corner of a given maze. The rat can move in four 
 * directions: down, left, right, and up. The maze is represented by a 2D grid where 1 indicates a valid path and 
 * 0 indicates a blocked cell.
 * 
 * The solution uses recursion and backtracking to explore all possible paths and stores the valid paths in a vector.
 * 
 * @class Solution
 * @brief Contains methods to solve the Rat in a Maze problem.
 * 
 * @method bool isSafe(vector<vector<int>> &mat, int n, int xind, int yind, vector<vector<int>>& visited)
 * @brief Checks if the current cell is safe to move to.
 * @param mat Reference to the maze matrix.
 * @param n Size of the maze (n x n).
 * @param xind Current x index (row).
 * @param yind Current y index (column).
 * @param visited Reference to the visited matrix to keep track of visited cells.
 * @return True if the cell is safe to move to, false otherwise.
 * 
 * @method void solve(vector<vector<int>> &mat, int n, vector<string>& ans, int xind, int yind, string output, vector<vector<int>> &visited)
 * @brief Recursively explores all possible paths from the current cell.
 * @param mat Reference to the maze matrix.
 * @param n Size of the maze (n x n).
 * @param ans Reference to the vector storing all valid paths.
 * @param xind Current x index (row).
 * @param yind Current y index (column).
 * @param output Current path as a string.
 * @param visited Reference to the visited matrix to keep track of visited cells.
 * 
 * @method vector<string> findPath(vector<vector<int>> &mat)
 * @brief Finds all possible paths from the top-left corner to the bottom-right corner of the maze.
 * @param mat Reference to the maze matrix.
 * @return Vector of strings, each representing a valid path.
 */
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
  
    bool isSafe(vector<vector<int>> &mat, int n, int xind, int yind, vector<vector<int>>& visited)
    {
        if((xind >= 0 && xind < n) && (yind >= 0 && yind < n) && mat[xind][yind] == 1 && visited[xind][yind] == 0)
        {
            return true;
        }
        return false;
    }
  
    void solve(vector<vector<int>> &mat, int n, vector<string>& ans, int xind, int yind, string output, vector<vector<int>> &visited)
    {
        if(xind == n - 1 and yind == n - 1)
        {
            ans.push_back(output);
            return;
        }
        
        visited[xind][yind] = 1;
        
        //down
        int newx = xind + 1;
        int newy = yind;
        if(isSafe(mat, n, newx, newy, visited))
        {
            output.push_back('D');
            solve(mat, n, ans, newx, newy, output, visited);
            output.pop_back();
        }
        
        //left
        newx = xind;
        newy = yind - 1;
        if(isSafe(mat, n, newx, newy, visited))
        {
            output.push_back('L');
            solve(mat, n, ans, newx, newy, output, visited);
            output.pop_back();
        }
        
        //right
        newx = xind;
        newy = yind + 1;
        if(isSafe(mat, n, newx, newy, visited))
        {
            output.push_back('R');
            solve(mat, n, ans, newx, newy, output, visited);
            output.pop_back();
        }
        
        //up
        newx = xind - 1;
        newy = yind;
        if(isSafe(mat, n, newx, newy, visited))
        {
            output.push_back('U');
            solve(mat, n, ans, newx, newy, output, visited);
            output.pop_back();
        }
        
        
        visited[xind][yind] = 0;
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &mat) {
        
        int n = mat.size();
        vector<string> ans;
        
        if(mat[0][0] == 0)
        {
            return ans;
        }
        
        string output = "";
        int xind = 0;
        int yind = 0;
        
        vector<vector<int>> visited(n, vector<int> (n, 0));
        
        solve(mat, n, ans, xind, yind, output, visited);
        
        sort(ans.begin(), ans.end());
        return ans;
    } 
};