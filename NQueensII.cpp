/*
52. N-Queens II
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],
 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
From <https://leetcode.com/problems/n-queens-ii/description/>


*/

class Solution {
public:
    int result = 0;

    bool isValid(vector<vector<int>> &board, int n, int col,int row) {
        int i, j;
        for (i = col; i >= 0; i--)
        {
            if (board[i][row] == 1) return true;
        }

        for (i = col, j = row; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1) return true;
        }

        for (i = col, j = row; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 1) return true;
        }

        return false;
    }

    int helper(vector<vector<int>> &board,int n,int COL) {
        if(COL == n) {
            ++result;
            return result;
        }
        for(int i = 0; i < n; i++) {
            if(isValid(board,n,COL,i) == false){
                board[COL][i] = 1;
                helper(board,n,COL+1);
                board[COL][i] = 0;
            }
        }
        return result;
    }


    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        return helper(board,n,0);
    }
};

