/*
305. Number of Islands II
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example:
Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:
Can you do it in time complexity O(k log mn), where k is the length of the positions?

From <https://leetcode.com/problems/number-of-islands-ii/description/>


*/

class Solution {
public:
    int find(vector<int> &parent, int i) {
        if(parent[i] == -1) {
            return i;
        }
        return find(parent,parent[i]);
    }

    void unionSet(vector<int> &parent, int i, int j) {
        int x = find(parent,i);
        int y = find(parent,j);

        if(x != y) {
            parent[y] = x;
        }
    }

    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<int> parent(m*n,-1);
        vector<vector<int>> grid(m,vector<int>(n,0));
        vector<int> result;
        int total = 0;

        if(m == 0 || n == 0) {
            return {};
        }

        for(auto item : positions) {
            int r = item.first;
            int c = item.second;
            set<int> roots;

            for(int i = 0; i < directions.size(); i++) {
                int x = r + directions[i][0];
                int y = c + directions[i][1];

                if(x >=0 && y >=0 && x < m && y < n && grid[x][y] == 1) {
                    roots.insert(find(parent,x*n+y));
                }
            }
            total -= (roots.size()-1);
            result.push_back(total);
            for(int i = 0; i < directions.size(); i++) {
                int x = r + directions[i][0];
                int y = c + directions[i][1];

                if(x >=0 && y >=0 && x < m && y < n && grid[x][y] == 1) {
                    unionSet(parent,r*n+c,x*n+y);
                }
            }
            grid[r][c] = 1;
        }

        return result;
    }
};

