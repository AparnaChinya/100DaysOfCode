/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

From <https://leetcode.com/problems/minimum-path-sum/description/>


*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> DP(grid.size(),vector<int>(grid[0].size(),0));
        DP[0][0] = grid[0][0];

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(i == 0 && j-1 >= 0) {
                    DP[i][j] = DP[i][j-1] + grid[i][j];
                } else if(j == 0 && i-1 >= 0) {
                    DP[i][j] = DP[i-1][j] + grid[i][j];
                } else if(i!=0 && j!= 0){
                    DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
                }
            }
        }
        return DP[grid.size()-1][grid[0].size()-1];
    }
};

