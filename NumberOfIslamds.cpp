/*Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
Input:
11110
11010
11000
00000
Output: 1
Example 2:
Input:
11000
11000
00100
00011
Output: 3

From <https://leetcode.com/explore/interview/card/microsoft/31/trees-and-graphs/185/>
*/
class Solution {
public:
    int rowSize = 0;
    int colmnSize = 0;

    void dfs(vector<vector<char>> &grid, int row, int column) {
        grid[row][column] = '0';

        if(row-1 >= 0 && grid[row-1][column] == '1') {
            dfs(grid,row-1,column);
        }
        if(row+1 < rowSize && grid[row+1][column] == '1') {
            dfs(grid,row+1,column);
        }
        if(column-1 >= 0 && grid[row][column-1] == '1') {
            dfs(grid,row,column-1);
        }
        if(column+1 < colmnSize && grid[row][column+1] == '1') {
            dfs(grid,row,column+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        rowSize = grid.size();
        if(rowSize == 0) {
            return 0;
        }
        colmnSize = grid[0].size();

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    island++;
                    dfs(grid,i,j);
                }
            }
        }
        return island;
    }
};

