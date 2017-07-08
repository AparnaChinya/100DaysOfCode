/*
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3

return [1,2,3]. 

From <https://leetcode.com/problems/binary-tree-preorder-traversal/> 


*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Nodes(TreeNode *root,vector<int>&n)
    {
        if(!root)return;
        n.push_back(root->val);
        Nodes(root->left,n);
        Nodes(root->right,n);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> n;
        Nodes(root,n);
        return n;
    }
};

