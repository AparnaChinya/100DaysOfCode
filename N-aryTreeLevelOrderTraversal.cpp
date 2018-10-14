/*
429. N-ary Tree Level Order Traversal
Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example, given a 3-ary tree:
 

 
We should return its level order traversal:
[
     [1],
     [3,2,4],
     [5,6]
]
 
Note:
	1. The depth of the tree is at most 1000.
	2. The total number of nodes is at most 5000.

From <https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/>

*/
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> result;
        queue<QueueEntry> myQueue;
        QueueEntry qEntry = {root,0};
        myQueue.push(qEntry);

        while(!myQueue.empty()) {
            int size = myQueue.size();

            //Remember to put the vector here
            vector<int> myVector;

            //For all the nodes in the queue
            for(int i = 0; i < size; i++) {
                auto qFront = myQueue.front();
                myQueue.pop();
                myVector.push_back(qFront.n->val);

                for(auto j = qFront.n->children.begin(); j != qFront.n->children.end(); j++) {
                    qEntry = {*j, qFront.depth + 1};
                    myQueue.push(qEntry);
                }
            }
            //Dont forget to check if myVector size is not 0
            if(myVector.size() > 0) {
                result.push_back(myVector);
            }
        }
        return result;
    }
};

