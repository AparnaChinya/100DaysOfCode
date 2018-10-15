/*
323. Number of Connected Components in an Undirected Graph
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
Example 1:
Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]
0          3
     |          |
     1 --- 2    4
Output: 2
Example 2:
Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
0           4
     |           |
     1 --- 2 --- 3
Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

From <https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/>

*/
class Solution {
public:
    //Make sure to pass the adjacencyList by reference
    void dfs(vector<vector<int>> &adjacencyList,int i, vector<bool> &visited) {
        if(visited[i] == true) {
            return;
        }
        visited[i] = true;

        for(auto j = adjacencyList[i].begin(); j!= adjacencyList[i].end(); j++) {
            if(visited[*j] == false) {
                dfs(adjacencyList,*j,visited);
            }
        }
    }

    int countComponents(int n, vector<pair<int, int>>& edges) {
        int numOfComponents = 0;
        vector<vector<int>> adjacencyList(n,vector<int>());
        vector<bool> visited(n,false);

        for(auto e : edges) {
            adjacencyList[e.first].push_back(e.second);
            adjacencyList[e.second].push_back(e.first);
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                numOfComponents++;
                dfs(adjacencyList,i,visited);
            }
        }

        return numOfComponents;
    }
};

