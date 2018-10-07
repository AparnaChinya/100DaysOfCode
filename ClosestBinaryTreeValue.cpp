/*
Closest Binary Search Tree Value

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Note:
	• Given target value is a floating point.
	• You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:
Input: root = [4,2,5,1,3], target = 3.714286
4
   / \
  2   5
 / \
1   3
Output: 4

From <https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/516>

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

    void helper(TreeNode* root, double target, double &result) {

        if(root == NULL) {
            return;
        }
        //Check the difference
        if(abs(root->val - target) <= abs(target-result)) {
            result = root->val;
        }
        //Can improve by going only through left or right subtree depending in the val of the target and key
        helper(root->left,target,result);
        helper(root->right,target,result);
    }

    int closestValue(TreeNode* root, double target) {
        if(root == NULL) {
            return 0;
        }
        //remember to initialize the result to the first root value
        double result = root->val;
        helper(root,target,result);
        return result;
    }
};

