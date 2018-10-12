/*
559. Maximum Depth of N-ary Tree
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
For example, given a 3-ary tree:
 

 
We should return its max depth, which is 3.
 
Note:
	1. The depth of the tree is at most 1000.
	2. The total number of nodes is at most 5000.

From <https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/>


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    struct QueueEntry {
        Node *n;
        int depth;
    };

    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        int d = INT_MIN;
        //Take the BFS apprach
        queue<QueueEntry> myQueue;
        QueueEntry qEntry = {root,1};
        myQueue.push(qEntry);

        while(!myQueue.empty()) {
            int size = myQueue.size();
            //For all the elements in the queue
            for(int i = 0; i < size; i++) {
                qEntry = myQueue.front();
                myQueue.pop();
                //For all the children of the element in the front of the queue
                for(auto j = qEntry.n->children.begin(); j != qEntry.n->children.end(); j++) {
                    myQueue.push({*j,qEntry.depth+1});
                    d = max(d,qEntry.depth+1);
                }
            }
        }
        //Returns maxDepth
        return d == INT_MIN ? 1 : d;

    }
};

