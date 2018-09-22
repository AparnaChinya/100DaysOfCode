/*
404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.
Example:
    3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

From <https://leetcode.com/problems/sum-of-left-leaves/description/>
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
    void sumOfLeftLeavesHelper(TreeNode *root, int &sum, bool isLeft) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL && isLeft) {
            sum += root->val;
        }
        sumOfLeftLeavesHelper(root->left,sum,true);
        sumOfLeftLeavesHelper(root->right,sum,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumOfLeftLeavesHelper(root,sum,false);
        return sum;
    }
};

