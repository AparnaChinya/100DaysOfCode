/*
463. Island Perimeter
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 
Example:
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:


From <https://leetcode.com/problems/island-perimeter/description/>

*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int repeat = 0;
        int sides = 0;
        int ROW = grid.size();
        int COL = grid[0].size();
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    sides++;

                    if(i-1 >=0 && grid[i-1][j] == 1) {
                        repeat++;
                    }
                    if(i+1 < ROW && grid[i+1][j] == 1) {
                        repeat++;
                    }
                    if(j-1 >=0 && grid[i][j-1] == 1) {
                        repeat++;
                    }
                    if(j+1 < COL && grid[i][j+1] == 1) {
                        repeat++;
                    }
                }
            }
        }
        cout << "Sides" << sides << " " << repeat ;
        return 4*sides - repeat;
    }
};

