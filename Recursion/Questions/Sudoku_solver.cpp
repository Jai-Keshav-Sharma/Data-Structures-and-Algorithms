// LeetCode 37. Sudoku Solver

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Checks if placing a given character in a specific cell of the Sudoku board is valid.
     * 
     * This function verifies whether a character 'c' can be placed at the position (row, col)
     * on the Sudoku board without violating the Sudoku rules. It ensures that:
     * - The character does not already exist in the same column.
     * - The character does not already exist in the same row.
     * - The character does not already exist in the 3x3 sub-grid containing the cell.
     * 
     * @param board A 2D vector representing the Sudoku board.
     *              Each cell contains a character, where '.' represents an empty cell.
     * @param row The row index of the cell to check.
     * @param col The column index of the cell to check.
     * @param c The character to be placed in the cell.
     * @return true If placing the character 'c' in the cell (row, col) is valid.
     * @return false If placing the character 'c' in the cell (row, col) violates Sudoku rules.
     */
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return false;
            if (board[row][i] == c)
                return false;
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
                return false;
        }
        return true;
    }

    /**
     * @brief Solves a Sudoku puzzle using backtracking.
     * 
     * This function attempts to solve a given Sudoku board by filling in the empty cells (denoted by '.')
     * with digits from '1' to '9'. It uses a recursive backtracking approach to explore all possible 
     * configurations and returns true if a valid solution is found.
     * 
     * @param board A 2D vector of characters representing the Sudoku board. 
     *              Empty cells are represented by '.' and filled cells contain digits '1' to '9'.
     * @return true If the Sudoku puzzle is successfully solved.
     * @return false If no valid solution exists for the given board.
     * 
     * @note This function modifies the input board in-place to reflect the solution.
     *       It assumes that the input board is a valid Sudoku puzzle.
     */
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board) { solve(board); }
};