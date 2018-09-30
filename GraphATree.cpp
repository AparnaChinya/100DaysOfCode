/*
Graph Valid Tree

Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
Example 1:
Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:
Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

From <https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/520>
*/
class Solution {
public:

    bool hasCycle(vector<vector<int>> &adjacencyList, vector<bool> &visited, int i, int parent) {
        if(visited[i] == true) {
            return true;
        }
        visited[i] = true;

        //For each of the vertex in the adjacencylist check if it is not itself and has a cycle
        for(auto j = adjacencyList[i].begin(); j != adjacencyList[i].end(); ++j) {
            if(*j != parent && hasCycle(adjacencyList,visited,*j,i)) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        vector<bool> visited(n,false);

        //Create the graph
        for(auto e : edges) {
            adjacencyList[e.first].push_back(e.second);
            adjacencyList[e.second].push_back(e.first);
        }

        //Check cycle
        if(hasCycle(adjacencyList,visited,0,-1)) {
            return false;
        }

        //Check connected components or not
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};

