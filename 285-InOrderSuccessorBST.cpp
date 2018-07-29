/* 285. Inorder Successor in BST
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.
Example 1:
Input: root = [2,1,3], p = 1
2
 / \
1   3
Output: 2
Example 2:
Input: root = [5,3,6,2,4,null,null,1], p = 6
5
     / \
    3   6
   / \
  2   4
 /
1
Output: null

From <https://leetcode.com/problems/inorder-successor-in-bst/description/>
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
    TreeNode *inOrderHelper(TreeNode *p) {
        while(p->left != NULL) {
            p = p->left;
        }
        return p;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL || p == NULL) {
            return NULL;
        }

        if(p->right != NULL) {
            return inOrderHelper(p->right);
        }

        TreeNode *successor = NULL;
        while(root != NULL) {
            if(root->val > p->val) {
                successor = root;
                root = root->left;
            } else if(root->val < p->val) {
                root = root->right;
            } else break;
        }
        return successor;
    }
};

