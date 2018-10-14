/*
783. Minimum Distance Between BST Nodes
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
Example :
Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.
The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
4
        /   \
      2      6
     / \
    1   3
while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:
	1. The size of the BST will be between 2 and 100.
	2. The BST is always valid, each node's value is an integer, and each node's value is different.

From <https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/>

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
    void helper(TreeNode *root, int &prev, int &diff) {
        if(root == NULL) {
            return;
        }

        helper(root->left,prev,diff);

        if(prev != INT_MIN && (root->val - prev) <= diff ) {
            diff = root->val - prev;
        }
        prev = root->val;

        helper(root->right,prev,diff);
    }

    int minDiffInBST(TreeNode* root) {
        int pre = INT_MIN;
        int diff = INT_MAX;
        helper(root,pre,diff);
        return diff;
    }
};

