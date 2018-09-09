/* 37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
	1. Each of the digits 1-9 must occur exactly once in each row.
	2. Each of the digits 1-9 must occur exactly once in each column.
	3. Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

From <https://leetcode.com/problems/sudoku-solver/description/>
*/

class Solution {
public:
    bool inRow(vector<vector<char>> &board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == c) {
                return true;
            }
        }
        return false;
    }
    bool inCol(vector<vector<char>> &board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) {
                return true;
            }
        }
        return false;
    }
    bool inBox(vector<vector<char>> &board, int row, int col, char c) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i+row][j+col] == c) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>> &board, int row, int col, char c) {
        return !inRow(board,row,col,c) && !inCol(board,row,col,c) && !inBox(board,row - row%3,col - col%3,c);
    }

    bool solveSudokuHelper(vector<vector<char>> &board) {
        //Check each cell in the grid
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                //If a cell is ., then check if a particular number fits in the cell
                if(board[row][col] == '.') {
                    for(char c = '1' ; c <= '9' ; c++) {
                        if(isSafe(board,row,col,c)) {
                            board[row][col] = c;

                            if(solveSudokuHelper(board)) {
                                return true;
                            }

                            board[row][col] = '.';

                        }
                    }
                    //return false if none of the numbers match
                    return false;
                }

            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};
