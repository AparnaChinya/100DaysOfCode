/*
329. Longest Increasing Path in a Matrix
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
Example 1:
Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:
Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

From <https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/>
*/
class Solution {
public:
    int row;
    int column;

    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &cache) {
        //Cache for memoization otherwise, gives timeout limit

        if(cache[i][j] != 0) {
            return cache[i][j];
        }

        //cout<< "R:" << i << " C:" << j << " " << matrix[i][j] << " " <<row << " " << column << endl;
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            //cout<< "R:" << i << " C" << j << " " << matrix[i][j] << " " << endl;
            cache[i][j] = max(cache[i][j],dfs(matrix,i-1,j,cache));
        }
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            //cout<< "R:" << i << " C" << j << " " << matrix[i][j] << " " << endl;
            cache[i][j] = max(cache[i][j],dfs(matrix,i,j-1,cache));
        }
        if(i+1 < row && matrix[i+1][j] > matrix[i][j]) {
            //cout<< "R:" << i << " C" << j << " " << matrix[i][j] << " " << endl;
            cache[i][j] = max(cache[i][j],dfs(matrix,i+1,j,cache));
        }
        if(j+1 < column && matrix[i][j+1] > matrix[i][j]) {
            //cout<< "R:" << i << " C" << j << " " << matrix[i][j] << " " << endl;
            cache[i][j] = max(cache[i][j],dfs(matrix,i,j+1,cache));
        }
        //return answer at the end
        return ++cache[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        row = matrix.size();

        if(row == 0) {
            return 0;
        }
        vector<vector<int>> cache(matrix.size()+1,vector<int>(matrix[0].size()+1,0));

        column = matrix[0].size();
        int answer = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                answer = max(answer,dfs(matrix,i,j,cache));
            }
        }
        return answer;
    }
};

