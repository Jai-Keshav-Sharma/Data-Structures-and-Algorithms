// LeetCode 51. N-Queens

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int row, int col, vector<string> &board,
                vector<vector<string>> &ans, int n)
    {
        int i = row;
        int j = col;

        // Note;
        // we only need to check upper diagonal towards left, lower diaginal
        // towards left and the row towards left for any potential queens only
        // towards left because at any step, we haven't placed any queen on
        // right side

        // left upper diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row--][col--] == 'Q')
                return false;
        }

        row = i;
        col = j;
        // current row towards left
        while (col >= 0)
        {
            if (board[row][col--] == 'Q')
            {
                return false;
            }
        }

        row = i;
        col = j;
        // lower left diagonal
        while (row < n && col >= 0)
        {
            if (board[row++][col--] == 'Q')
                return false;
        }

        return true;
    }

    /**
     * @brief Solves the N-Queens problem using recursion and backtracking.
     *
     * This function attempts to place queens on the chessboard column by column.
     * If a valid configuration is found where no two queens attack each other,
     * the configuration is added to the result.
     *
     * @param col The current column being processed.
     * @param board A reference to the chessboard represented as a vector of strings,
     *              where each string represents a row. A 'Q' indicates a queen,
     *              and a '.' indicates an empty space.
     * @param ans A reference to the vector of solutions, where each solution is
     *            a vector of strings representing a valid chessboard configuration.
     * @param n The size of the chessboard (n x n).
     */
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               int n)
    {
        if (n == col)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, ans, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
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

        solve(0, board, ans, n);
        return ans;
    }
};