/* 62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

From <https://leetcode.com/problems/unique-paths/description/>

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int possiblePaths[m+1][n+1] = {0};

        for(int i = 0; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(i == 0 || j == 0) {
                    possiblePaths[i][j] = 1;
                } else {
                    possiblePaths[i][j] = possiblePaths[i-1][j] + possiblePaths[i][j-1];
                }
            }
        }
        return possiblePaths[m-1][n-1];
    }
};

