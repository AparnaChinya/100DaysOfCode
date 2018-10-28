/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

From <https://leetcode.com/problems/n-queens/description/>


*/

class Solution {
public:
    bool isValid(vector<string> &board, int row, int col, int n) {

        //Check the column
        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        //Check the row
        for(int i = 0; i < n; i++) {
            if(board[row][i] == 'Q') {
                return false;
            }
        }

        //Check the diagonal
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(row+col == i+j || row-col == i-j) {
                    if(board[i][j] == 'Q') {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void solveNQueensHelper(vector<string> &board, int col, int n, vector<vector<string>> &result) {
        if(col == n) {
            result.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isValid(board,row,col,n)) {
                board[row][col] = 'Q';
                solveNQueensHelper(board,col+1,n,result);
                board[row][col] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        solveNQueensHelper(board,0,n,result);
        return result;
    }
};

