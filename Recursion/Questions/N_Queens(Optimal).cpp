// LeetCode 51. N-Queens

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Solves the N-Queens problem using backtracking and stores all possible solutions.
     * 
     * This function attempts to place queens on an N x N chessboard such that no two queens
     * threaten each other. It uses backtracking to explore all possible configurations and
     * stores valid solutions in the `ans` vector.
     * 
     * @param col The current column being processed.
     * @param board A reference to the current state of the chessboard, represented as a vector of strings.
     *              Each string represents a row, where 'Q' indicates a queen and '.' indicates an empty cell.
     * @param ans A reference to a vector of vectors of strings, where each inner vector represents a valid
     *            configuration of the chessboard.
     * @param leftRow A reference to a vector that tracks whether a queen is placed in a specific row.
     *                If leftRow[i] is 1, it means a queen is placed in row i.
     * @param lowerDiag A reference to a vector that tracks whether a queen is placed in a specific lower diagonal.
     *                  The index is calculated as (row + col).
     * @param upperDiag A reference to a vector that tracks whether a queen is placed in a specific upper diagonal.
     *                  The index is calculated as ((n - 1) + col - row).
     * @param n The size of the chessboard (N x N).
     * 
     * @note This function modifies the `board`, `leftRow`, `lowerDiag`, and `upperDiag` vectors during execution
     *       and restores their state after backtracking.
     */
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftRow, vector<int> &lowerDiag,
               vector<int> &upperDiag, int n)
    {
        if (n == col)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] != 1 && lowerDiag[row + col] != 1 &&
                upperDiag[(n - 1) + col - row] != 1)
            {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[(n - 1) + col - row] = 1;

                solve(col + 1, board, ans, leftRow, lowerDiag, upperDiag, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[(n - 1) + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);

        solve(0, board, ans, leftRow, lowerDiag, upperDiag, n);

        return ans;
    }
};