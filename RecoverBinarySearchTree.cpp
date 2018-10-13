/*
99. Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Example 1:
Input: [1,3,null,null,2]
   1
  /
 3
  \
   2
Output: [3,1,null,null,2]
   3
  /
 1
  \
   2
Example 2:
Input: [3,1,4,null,null,2]
3
 / \
1   4
   /
  2
Output: [2,1,4,null,null,3]
2
 / \
1   4
   /
  3
Follow up:
	• A solution using O(n) space is pretty straight forward.
	• Could you devise a constant space solution?

From <https://leetcode.com/problems/recover-binary-search-tree/description/>
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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *previous = new TreeNode(INT_MIN);

    void Recurse(TreeNode* root) {
        //Simple Inorder Traversal
        if (root == NULL) {
            return;
        }
        Recurse(root->left);

        if (first == NULL && previous->val >= root->val) {
            first = previous;
        }

        if (first != NULL && previous->val >= root->val) {
            second = root;
        }
        previous = root;

        Recurse(root->right);

    }

    void recoverTree(TreeNode* root) {
        Recurse(root);
        swap(first->val,second->val);
    }
};
