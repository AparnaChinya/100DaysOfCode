/* CTCI 4.7
BuildOrder - given a list of Projects and dependencies, find build order for the projects to be built.

 */
#include <iostream>
//Topological Sort

// Graph class
class Graph {
    int numOfNodes;
    list<int> *adjacencyList;

    public:
    Graph(int numOfNodes);
    void addEdges(int from, int to);
    void topologicalSort();
    bool buildOrder(int nodeNumber, bool visited[],bool recurStack[], stack<int> &resultorder);
};

//Initializing the number of nodes in the graph
Graph::Graph(int numOfNodes) {
    this->numOfNodes = numOfNodes;
    adjacencyList = new list<int>[numOfNodes];
}

//Adding the edges in adjacency list
void Graph::addEdges(int from, int to) {
    adjacencyList[from].push_back(to);
}

//Calling DFS for each unvisited node in the graph
void Graph::topologicalSort() {
    bool visited[numOfNodes] = {false};     //Keeps track of visited nodes in the graph
    bool recuStack[numOfNodes] = {false};   // Keeps track of the recursion stack in the graph
    stack<int> resultOrder;                 // Topological order of visit of the nodes
    bool isCycle = false;

    for(int i = 0; i < numOfNodes; i++) {
        if(buildOrder(i,visited,recuStack,resultOrder)) {
            isCycle = true;
            break;
        }
    }
    if(!isCycle) {
        cout << "Order of build of the projects: \n";
        while(!resultOrder.empty()) {
            cout << (char)('a' + resultOrder.top()) << " ";
            resultOrder.pop();
        }
        return;
    } else {
        cout << "There is circular dependency!";
        return;
    }


}

//This is where all the magic happens!
bool Graph::buildOrder(int nodeNumber, bool visited[],bool recurStack[], stack<int> &resultOrder) {

    if(!visited[nodeNumber]) {
        visited[nodeNumber] = true;
        recurStack[nodeNumber] = true;

        //For each edge of the node
        for(auto i = adjacencyList[nodeNumber].begin(); i != adjacencyList[nodeNumber].end();i++) {
            if(!visited[*i] && buildOrder(*i,visited,recurStack,resultOrder)) {
                return true;
            } else if(recurStack[*i]) {
                return true;
            }
        }
        //Add the node to the topological sorting order
        resultOrder.push(nodeNumber);
    }
    recurStack[nodeNumber] = false;
    return false;
}



int main() {
    std::cout << "Hello World!\n";
    vector<char> projects = {'a','b','c','d','e','f'};
    vector<vector<char>> dependencies = {{'d','a'},{'b','f'},{'d','b'},{'a','f'},{'c','d'}};

    // Assiging each project as a node in the graph
    Graph g(projects.size());

    // Assigning each dependency as an edge in the directed graph.
    cout << "Adding Edges...\n";
    for(int i = 0; i < dependencies.size(); i++) {
        cout << dependencies[i][0] << " -> " << dependencies[i][1] << endl;
        g.addEdges(dependencies[i][0]-'a',dependencies[i][1]-'a');
    }

    //TopologicalSort
    g.topologicalSort();
}