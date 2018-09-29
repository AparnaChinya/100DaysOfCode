/*
Two Sum IV - Input is a BST

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7
Target = 28
Output: False

From <https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/487>
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
    bool findTargetHelper(TreeNode* root, int k, map<int,bool> &myMap) {
        if(root == NULL) {
            return false;
        }
        // if target - present value is there in map returns true
        if(root != NULL && myMap.find(k - root->val) != myMap.end()) {
            return true;
        }

        //Add to map
        myMap[root->val] = true;

        return findTargetHelper(root->left,k,myMap) || findTargetHelper(root->right,k,myMap);

    }

    bool findTarget(TreeNode* root, int k) {
        map<int,bool> myMap;

        return findTargetHelper(root,k,myMap);

    }
};

