/*
694. Number of Distinct Islands
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.

From <https://leetcode.com/problems/number-of-distinct-islands/description/>
*/

class Solution {
public:
    int row;
    int col;

    void dfs(vector<vector<int>>& grid, int r, int c,int di, vector<int> &mySet,vector<vector<bool>> &visited) {
        if(r >= 0 && c >= 0 && r < row && c < col && !visited[r][c] && grid[r][c] == 1) {
            visited[r][c] = true;
            mySet.push_back(di);
            dfs(grid,r+1,c,1,mySet,visited);
            dfs(grid,r-1,c,2,mySet,visited);
            dfs(grid,r,c+1,3,mySet,visited);
            dfs(grid,r,c-1,4,mySet,visited);
            //Not sure why this is added.
            mySet.push_back(0);
        }
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<int>> mySet;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int distinctIslands = 0;
        row = grid.size();
        col = grid[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                vector<int> path;
                //DFS with vector of paths
                dfs(grid,i,j,distinctIslands,path,visited);
                if(path.size() > 0) {
                    mySet.insert(path);
                }
            }
        }
        return mySet.size();
    }
};


