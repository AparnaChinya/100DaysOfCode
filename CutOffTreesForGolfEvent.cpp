/*
675. Cut Off Trees for Golf Event
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:
	1. 0 represents the obstacle can't be reached.
	2. 1 represents the ground can be walked through.
	3. The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).
You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.
You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.
Example 1:
Input:
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:
Input:
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:
Input:
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
Hint: size of the given matrix will not exceed 50x50.

From <https://leetcode.com/problems/cut-off-trees-for-golf-event/description/>

*/

class Solution {
public:
    struct Trees {
        int height;
        int r;
        int c;
    };

    struct compare {
        bool operator ()(Trees a, Trees b) {
            return a.height < b.height;
        }
    };

    int ROW;
    int COL;
    vector<vector<int>> direction = {{-1,0},{0,-1},{1,0},{0,1}};

    int cutOffTree(vector<vector<int>>& forest) {
        ROW = forest.size();
        if(ROW == 0) {
            return 0;
        }
        COL = forest[0].size();
        vector<Trees> treeFeature;
        int result = 0;

        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                if(forest[i][j] > 0) {
                    Trees t = {forest[i][j],i,j};
                    treeFeature.push_back(t);
                }
            }
        }
        sort(treeFeature.begin(),treeFeature.end(),compare());

        // for(int i = 0; i < treeFeature.size(); i++) {
        //     auto t = treeFeature[i];
        //     cout << t.height << t.r << t.c << endl;
        // }
        int startX = 0;
        int startY = 0;

        for(int i = 0; i < treeFeature.size(); i++) {
            int steps = BFS(forest,startX,startY,treeFeature[i].r,treeFeature[i].c);
            if(steps == -1) {
                return -1;
            }
            result += steps;
            startX = treeFeature[i].r;
            startY = treeFeature[i].c;
        }

        return result;
    }

    int BFS(vector<vector<int>> &forest,int startX, int startY,int destX, int destY) {
        if(destX == startX && destY == startY) {
            return 0;
        }
        queue<pair<int,int>> myQueue;
        myQueue.push(make_pair(startX,startY));
        int steps = 0;
        vector<vector<int>> visited(ROW,vector<int>(COL,false));
        visited[startX][startY] = true;

        while(!myQueue.empty()) {
            int size = myQueue.size();
            steps++;
            for(int i = 0; i < size; i++) {
                auto temp = myQueue.front();
                myQueue.pop();
                //cout << temp.first << " " << temp.second << endl;

                for(int j = 0; j < direction.size(); j++) {
                    int x = temp.first + direction[j][0];
                    int y = temp.second + direction[j][1];
                    //cout << x << " " << y << endl;
                    if(x >=0 && y >=0 && x < ROW && y < COL && visited[x][y] == 0 && forest[x][y] > 0) {
                        if(x == destX && y == destY) {
                            return steps;
                        }
                        visited[x][y] = true;
                        myQueue.push(make_pair(x,y));
                    }
                }

            }
        }

        return -1;
    }
};

