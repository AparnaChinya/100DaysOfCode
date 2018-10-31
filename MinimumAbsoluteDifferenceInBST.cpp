/*
530. Minimum Absolute Difference in BST
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Example:
Input:
1
    \
     3
    /
   2
Output:
1
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 
Note: There are at least two nodes in this BST.

From <https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/>

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
    int result = INT_MAX;
    TreeNode *previous = NULL;

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) {
            return result;
        }
        getMinimumDifference(root->left);
        if(previous != NULL) {
            result = min(result,abs(root->val - previous->val));
        }
        previous = root;
        getMinimumDifference(root->right);
        return result;
    }
};

