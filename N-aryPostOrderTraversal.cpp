/*
590. N-ary Tree Postorder Traversal
Given an n-ary tree, return the postorder traversal of its nodes' values.
For example, given a 3-ary tree:
 

 
Return its postorder traversal as: [5,6,3,2,4,1].
 
Note:
Recursive solution is trivial, could you do it iteratively?

From <https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/>

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
    void postOrderHelper(Node *root, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        for(auto j = root->children.begin(); j != root->children.end(); j++) {
            postOrderHelper(*j,result);
        }
        result.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        postOrderHelper(root,result);
        return result;
    }
};

