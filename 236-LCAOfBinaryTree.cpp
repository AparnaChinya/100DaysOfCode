/*
236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.
Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.
Note:
	• All of the nodes' values will be unique.
	• p and q are different and both values will exist in the binary tree.

From <https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/>

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
    //Check if node is present in the tree
    bool cover(TreeNode *root, TreeNode *node) {
        if(root == NULL) {
            return false;
        }
        if(root == node) {
            return true;
        }
        return cover(root->left,node) || cover(root->right,node);
    }

    //return the LCA
    TreeNode *AncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        //Check if p is present in the left subtree  and if q is present in the left subtree
        bool ispOnLeft = cover(root->left,p);
        bool isqOnLeft = cover(root->left,q);

        //If they are on different subtree, return root
        if(ispOnLeft != isqOnLeft) {
            return root;
        }

        //get either right or left child of root depending on where q/p is present
        TreeNode *childNode = ispOnLeft? root->left : root->right;
        return AncestorHelper(childNode,p,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //If root is null or if p or q is root
        if (root == NULL || root == p || root == q) {
            return root;
        }
        //Check if p and q is present in the tree
        if (!cover(root,p) || !cover(root,q)) {
            return NULL;
        }
        return AncestorHelper(root,p,q);
    }
};

