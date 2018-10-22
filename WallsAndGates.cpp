/*
286. Walls and Gates
You are given a m x n 2D grid initialized with these three possible values.
	1. -1 - A wall or an obstacle.
	2. 0 - A gate.
	3. INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
Example: 
Given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

From <https://leetcode.com/problems/walls-and-gates/description/>

*/

class Solution {
public:
    struct QueueEntry {
        int r;
        int c;
        int distance;
    };
    void wallsAndGates(vector<vector<int>>& rooms) {
        int ROW = rooms.size();
        if(ROW == 0) {
            return;
        }
        int COL = rooms[0].size();
        vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
        queue<QueueEntry> myQueue;

        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(rooms[i][j] == 0) {
                    QueueEntry q = {i,j,0};
                    myQueue.push(q);
                }
            }
        }
        while(!myQueue.empty()) {
            int size = myQueue.size();

            for(int i = 0; i < size; i++) {
                auto temp = myQueue.front();
                myQueue.pop();

                for(int j = 0; j < 4; j++) {

                    int x = temp.r + directions[j][0];
                    int y = temp.c + directions[j][1];
                    int d = temp.distance + 1;
                    QueueEntry q = {x,y,d};

                    //REMEMBER to put the OR conditions
                    if(x < 0 || x >= ROW || y < 0 || y >= COL || rooms[x][y] != INT_MAX) {
                        continue;
                    }
                    cout << x << y << d <<endl;
                    rooms[x][y] = min(rooms[x][y],temp.distance + 1);
                    myQueue.push(q);

                }
            }
        }
    }
};

