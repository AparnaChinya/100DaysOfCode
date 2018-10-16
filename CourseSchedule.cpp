/*
207. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Example 1:
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:
	1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
	2. You may assume that there are no duplicate edges in the input prerequisites.


From <https://leetcode.com/problems/course-schedule/description/>
*/

class Solution {
public:
    vector<int> countInDegree(vector<unordered_set<int>> &myGraph, int numCourses) {
        vector<int> inDegree(myGraph.size(),0);
        for(int i = 0; i < myGraph.size(); i++) {
            for(auto j = myGraph[i].begin(); j!= myGraph[i].end(); j++) {
                inDegree[*j]++;
            }
        }
        return inDegree;
    }

    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        //Build graph from 2 to 1
        vector<unordered_set<int>> myGraph = buildGraph(prerequisites,numCourses);

        //Count indegree
        vector<int> inDegrees = countInDegree(myGraph,numCourses);

        //For all the courses
        for(int i = 0; i < numCourses; i++) {
            int j = 0;

            //Check if a node doesnt have indegree
            for(; j < numCourses; j++) {
                if(!inDegrees[j]) {
                    break;
                }
            }
            //If there is no such node which has indegree, then there is a cycle
            if(j == numCourses) {
                return false;
            }
            // Else set the nodes visited to -1
            inDegrees[j] = -1;

            //reduce the indegree count
            for(auto item : myGraph[j]) {
                inDegrees[item]--;
            }
        }

        return true;
    }


    vector<unordered_set<int>> buildGraph(vector<pair<int, int>> &prerequisites,int numCourses) {
        vector<unordered_set<int>> myGraph(numCourses);
        for(auto item : prerequisites) {
            myGraph[item.second].insert(item.first);
        }
        return myGraph;
    }
};


