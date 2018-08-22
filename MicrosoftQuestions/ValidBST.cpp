/*
Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
	• The left subtree of a node contains only nodes with keys less than the node's key.
	• The right subtree of a node contains only nodes with keys greater than the node's key.
	• Both the left and right subtrees must also be binary search trees.
Example 1:
Input:
    2
   / \
  1   3
Output: true
Example 2:
    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.

From <https://leetcode.com/explore/interview/card/microsoft/31/trees-and-graphs/152/>

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }

        return isValidBSTHelper(root,NULL,NULL);
    }

    bool isValidBSTHelper(TreeNode *root, TreeNode *min, TreeNode* max) {
        if(root == NULL) {
            return true;
        }
        if(min != NULL && root->val <= min->val) {
            return false;
        }
        if(max != NULL && root->val >= max->val) {
            return false;
        }
        return isValidBSTHelper(root->left,min,root) && isValidBSTHelper(root->right,root,max);
    }
};

