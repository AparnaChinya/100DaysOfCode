/*
250. Count Univalue Subtrees
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.
Example :
Input:  root = [5,1,5,5,5,null,5]
5
             / \
            1   5
           / \   \
          5   5   5
Output: 4

From <https://leetcode.com/problems/count-univalue-subtrees/description/>

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
    bool helper(TreeNode* root, int &unique) {
        if(root == NULL) {
            return true;
        }

        bool left = helper(root->left,unique);
        bool right = helper(root->right,unique);

        if(left == false || right == false ) {
            return false;
        }

        if(root->left && root->val != root->left->val) {
            return false;
        }
        if(root->right && root->val != root->right->val) {
            return false;
        }
        ++unique;
        return true;
    }

    int countUnivalSubtrees(TreeNode* root) {
        int unique = 0;
        helper(root,unique);
        return unique;
    }
};

