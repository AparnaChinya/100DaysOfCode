/*
538. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
Example:
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13
Output: The root of a Greater Tree like this:
             18
            /   \
          20     13


From <https://leetcode.com/problems/convert-bst-to-greater-tree/description/>
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
    int sum = 0;
    TreeNode *helper(TreeNode *root) {
        if(root == NULL) {
            return root;
        }
        helper(root->right);
        sum += root->val;
        root->val = sum;
        helper(root->left);
        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        return helper(root);
    }
};

