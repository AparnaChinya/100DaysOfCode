/* 63. Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
Note: m and n will be at most 100.
Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

From <https://leetcode.com/problems/unique-paths-ii/description/>  */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> possiblePaths(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1,0));

        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        possiblePaths[0][1] = 1;
        for(int i = 1; i <= obstacleGrid.size(); i++) {
            for(int j = 1; j <= obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i-1][j-1] != 1) {
                    possiblePaths[i][j] = possiblePaths[i-1][j] + possiblePaths[i][j-1];
                } cout<< possiblePaths[i][j] << " ";


            }cout<<endl;
        }

        return possiblePaths[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};

