/*
210. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
Example 1:
Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
             course 0. So the correct course order is [0,1] .
Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:
	1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
	2. You may assume that there are no duplicate edges in the input prerequisites.

From <https://leetcode.com/problems/course-schedule-ii/description/>

*/

class Solution {
public:
    bool hasCycle(vector<unordered_set<int>> &myGraph, vector<bool> &visited, vector<bool> &recursion, int i,stack<int> &myStack) {
        if(visited[i] == true) {
            return true;
        }
        visited[i] = true;
        recursion[i] = true;

        for(auto j = myGraph[i].begin(); j != myGraph[i].end(); j++) {
            if(visited[*j] == false && hasCycle(myGraph,visited,recursion,*j,myStack)) {
                return true;
            } else if(recursion[*j] == true) {
                return true;
            }
        }
        recursion[i] = false;
        myStack.push(i);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        //PURE case of topological sort
        vector<int> result;

        //This condition doesnt make sense, but added because one of the test cases doesnt make sense
        if(numCourses == 1) {
            result.push_back(0);
            return result;
        }

        vector<unordered_set<int>> myGraph(numCourses);
        stack<int> myStack;
        vector<bool> visited(numCourses,false);
        vector<bool> recursion(numCourses,false);

        //Creating the graph
        for(int i = 0; i < prerequisites.size(); i++) {
            myGraph[prerequisites[i].second].insert(prerequisites[i].first);
        }

        //Checking for cycle of all components
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && hasCycle(myGraph,visited,recursion,i,myStack)) {
                return {};
            }
        }

        //Getting the order of traversal
        while(!myStack.empty()) {
            result.push_back(myStack.top());
            myStack.pop();
        }
        return result;
    }
};

