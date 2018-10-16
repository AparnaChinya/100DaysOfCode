/*
490. The Maze
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
 
Example 1:
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)
Output: false
Explanation: There is no way for the ball to stop at the destination.

 
Note:
	1. There is only one ball and one destination in the maze.
	2. Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
	3. The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
	4. The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

From <https://leetcode.com/problems/the-maze/description/>

*/

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        //Directions
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        //BFS queue
        queue<pair<int,int>> myQueue;
        //Visited nodes
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size()));
        //Add starting points to the queue
        myQueue.push(make_pair(start[0],start[1]));

        //While queue is not empty
        while(!myQueue.empty()) {
            auto qFront = myQueue.front();
            myQueue.pop();

            //Check if destination is reached
            if(qFront.first == destination[0] && qFront.second == destination[1]) {
                return true;
            }

            //For all the four directions
            for(int i = 0; i < directions.size(); i++) {
                //Go to the new direction
                int x = qFront.first + directions[i][0];
                int y = qFront.second + directions[i][1];

                //Traverse until you hit the wall
                while(x >=0 && y >=0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0) {
                    x += directions[i][0];
                    y += directions[i][1];
                }

                //Add visited nodes to queue ?? DOUBT
                if(!visited[x-directions[i][0]][y-directions[i][1]]) {
                    visited[x-directions[i][0]][y-directions[i][1]] = true;
                    myQueue.push(make_pair(x-directions[i][0],y-directions[i][1]));
                }
            }
        }


        return false;
    }
};

