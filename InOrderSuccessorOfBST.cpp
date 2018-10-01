/*
Inorder Successor in BST

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

From <https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/519/>

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        //If the node has a right child
        if(p->right != NULL) {
            TreeNode *current = p->right;
            while(current->left != NULL) {
                current = current->left;
            }
            return current;
        }

        //if node doesnt have right child
        TreeNode *successor = NULL;

        while(root != NULL) {
            if(p->val < root->val) {
                successor = root;
                root = root->left;
            } else if(p->val > root->val) {
                root = root->right;
            } else if(p->val == root->val){
                break;
            }
        }
        return successor;
    }
};

