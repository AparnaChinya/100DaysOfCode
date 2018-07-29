/* CTCI 4.7
BuildOrder - given a list of Projects and dependencies, find build order for the projects to be built.

 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//Creating a graph class with total number of nodes, adjacency list, addEdge
class Graph {
    int nodes;
    list<int> *adjacencyList;

    public:
    Graph(int nodes);
    void addEdge(int from, int to);
    void topologicalSort();
    bool dfsHelper(int i, bool visited[], stack<int> &myStack,  bool recursionStack[]);
};

Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjacencyList = new list<int>[nodes];
}
//Add edges
void Graph::addEdge(int from, int to) {
    adjacencyList[from].push_back(to);

}

// Adds nodes to stack in topological form, return false if there is a cycle
bool Graph::dfsHelper(int i, bool visited[], stack<int> &myStack, bool recursionStack[]) {

    if(visited[i] == false) {

        recursionStack[i] = true;
        visited[i] = true;

        for(auto j = adjacencyList[i].begin(); j != adjacencyList[i].end(); j++) {
            if(!visited[*j] && dfsHelper(*j,visited,myStack,recursionStack)){
                return true;
            } else if(recursionStack[*j]) {
                return true;
            }
        }
        myStack.push(i);

    }
    recursionStack[i] = false;
    return false;
}

void Graph::topologicalSort(){

    bool visited[nodes] = {false};
    bool recursionStack[nodes] = {false};
    stack<int> myStack;
    bool isCycle = false;

    // Applies DFS on the graph while keeping track of the recursionStack to check for cycles
    // myStack contains the nodes in topologicalForm
    for(int i = 0; i < nodes; i++) {
            if(dfsHelper(i,visited,myStack,recursionStack)) {
                isCycle = true;
                break;
            }
    }

    while(!myStack.empty() && !isCycle) {

        cout << (char) ('a' + myStack.top()) << " ";
        myStack.pop();
    }
    if(isCycle) {
        cout << "-1";
    }
}

int main() {
    //BuildOrder
    vector<char> projects = {'a','b','c','d','e','f'};
    vector<vector<char>> dependency = {{'d','a'},{'b','f'},{'d','b'},{'a','f'},{'c','d'}};

    //Form the graph
    Graph g(projects.size());
    for(int i=0; i < dependency.size(); i++) {
        cout << dependency[i][0] << "->" << dependency[i][1] << endl;
        g.addEdge(dependency[i][0]-'a',dependency[i][1]-'a');
    }

    g.topologicalSort();
}






