/* 572. Subtree of Another Tree

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
Example 1:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

From <https://leetcode.com/problems/subtree-of-another-tree/description/>  */

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
    //Check if the two trees starting at same nodes match
    bool isMatch(TreeNode *s, TreeNode *t) {
        if(s==NULL && t==NULL) {
            return true;
        }
        if(s==NULL || t==NULL) {
            return false;
        }
        if(s->val != t->val) {
            return false;
        }

        return isMatch(s->right,t->right) && isMatch(s->left,t->left);
    }
    //For all the nodes in s which match the first node in t, check the subtrees
    bool isSubTreeHelper(TreeNode* s, TreeNode *t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL) {
            return false;
        }
        if(s->val == t->val && isMatch(s,t)) {
            return true;
        }
        return isSubTreeHelper(s->right,t) || isSubTreeHelper(s->left,t);
    }
    // Return false/true based on the base cases
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) {
            return true;
        }
        if(s == NULL || t == NULL) {
            return false;
        }

        return isSubTreeHelper(s,t);
    }
};

