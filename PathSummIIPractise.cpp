/* 113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.
Example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
From <https://leetcode.com/problems/path-sum-ii/description/>
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
    vector<vector<int>> solution;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathSumHelper(root,sum);
        return solution;
    }

    //If the root is null, just return
    // Add the current node to the path
    //If the current node is the leaf -> and is equal to the target, add the path to the solution.
    //Call the left side of the tree and right side of the tree by subtracting the current roots value
    //pop the node in the path

    void pathSumHelper(TreeNode* root, int sum) {
        if(root == NULL) {
            return;
        }
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum) {
            solution.push_back(path);
        }
        pathSumHelper(root->left,sum-root->val);
        pathSumHelper(root->right,sum-root->val);

        path.pop_back();
    }


};

