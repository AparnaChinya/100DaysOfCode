/*
272. Closest Binary Search Tree Value II
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
Note:
	• Given target value is a floating point.
	• You may assume k is always valid, that is: k ≤ total nodes.
	• You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Example:
Input: root = [4,2,5,1,3], target = 3.714286, and k = 2
4
   / \
  2   5
 / \
1   3
Output: [4,3]
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

From <https://leetcode.com/problems/closest-binary-search-tree-value-ii/description/>

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
    priority_queue<pair<double,int>> myQueue;

    void helper(TreeNode *root, double target, int k, int parent) {
        if(root == NULL) {
            return;
        }
        myQueue.push(make_pair(abs(target-root->val),root->val));

        if(myQueue.size() > k) {
            myQueue.pop();
        }

        helper(root->left,target,k,root->val);
        helper(root->right,target,k,root->val);

    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        helper(root,target,k,root->val);
        vector<int> result;

        while(!myQueue.empty()) {
            result.push_back(myQueue.top().second);
            myQueue.pop();
        }

        return result;
    }
};

