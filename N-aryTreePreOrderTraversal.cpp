/*
589. N-ary Tree Preorder Traversal
Given an n-ary tree, return the preorder traversal of its nodes' values.
For example, given a 3-ary tree:
 

 
Return its preorder traversal as: [1,3,5,6,2,4].
 
Note:
Recursive solution is trivial, could you do it iteratively?

From <https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/>

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
    //Remember to pass the result by reference and not value.
    void preOrderHelper(Node *root, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        result.push_back(root->val);

        for(auto j = root->children.begin(); j != root->children.end(); j++) {
            preOrderHelper(*j,result);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        preOrderHelper(root,result);
        return result;
    }
};

