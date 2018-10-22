/*
317. Shortest Distance from All Buildings
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
	• Each 0 marks an empty land which you can pass by freely.
	• Each 1 marks a building which you cannot pass through.
	• Each 2 marks an obstacle which you cannot pass through.
Example:
Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

From <https://leetcode.com/problems/shortest-distance-from-all-buildings/description/>
*/

class Solution {
public:
    bool BFS(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &hitBuildings,vector<vector<int>> &totalDistanceToAllBuildings,
             int ROW, int COL,int buildings) {
        vector<vector<int>> directions = {{-1,0},{0,-1},{0,1},{1,0}};
        vector<vector<bool>> visited(ROW,vector<bool>(COL,false));
        queue<pair<int,int>> myQueue;
        visited[r][c] = true;
        myQueue.push(make_pair(r,c));
        int reachBuildings = 1;
        int distance = 0;

        while(!myQueue.empty()) {
            int size = myQueue.size();
            distance++;

            for(int i = 0; i < size; i++) {
                auto temp = myQueue.front();
                myQueue.pop();

                for(int j = 0; j < directions.size(); j++) {
                    int x = temp.first + directions[j][0];
                    int y = temp.second + directions[j][1];

                    if(x >=0 && y >= 0 && x < ROW && y < COL && !visited[x][y]) {
                        visited[x][y] = true;
                        if(grid[x][y] == 0) {
                            myQueue.push(make_pair(x,y));
                            hitBuildings[x][y] += 1;
                            totalDistanceToAllBuildings[x][y] += distance;
                        } else if(grid[x][y] == 1) {
                            reachBuildings++;
                        }
                    }
                }
            }
        }

        return reachBuildings == buildings;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        int ROW = grid.size();
        if(ROW == 0) {
            return -1;
        }
        int COL = grid[0].size();

        int buildings = 0;
        //Count the number of buildings
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(grid[i][j] == 1) {
                    buildings++;
                }
            }
        }
        vector<vector<int>> hitBuildings(ROW,vector<int>(COL,0));
        vector<vector<int>> totalDistanceToAllBuildings(ROW,vector<int>(COL,0));

        //Check BFS and populate hte distance of each cell from a building and number of buildings the cell can reach
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(grid[i][j] == 1) {
                    if(!BFS(grid,i,j,hitBuildings,totalDistanceToAllBuildings,ROW,COL,buildings)) {
                        return -1;
                    }
                }
            }
        }

        int result = INT_MAX;

        //Get the minimum distance
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(grid[i][j] == 0 && hitBuildings[i][j] == buildings) {
                    result = min(result,totalDistanceToAllBuildings[i][j]);
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

