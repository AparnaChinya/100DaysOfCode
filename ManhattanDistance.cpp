/*
296. Best Meeting Point
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
Example:
Input:
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
Output: 6
Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance
             of 2+2+2=6 is minimal. So return 6.

From <https://leetcode.com/problems/best-meeting-point/description/>

*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> column;

        //Get all the rows and column index of the cells which are 1
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    rows.push_back(i);
                    column.push_back(j);
                }
            }
        }
        //Sort these cells which are one based on the index
        sort(rows.begin(),rows.end());
        sort(column.begin(),column.end());

        int distance = 0;
        //Get the midpoint of both x and y co-ordinates
        int x = rows[rows.size()/2];
        int y = column[column.size()/2];

        //Add the distance based on Manhattan formular
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    distance += abs(x-i) + abs(y-j);
                }
            }
        }
        return distance;
    }
};

