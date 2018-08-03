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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> solution;
        if(root == NULL) {
            return solution;
        }
        pathSumHelper(root,sum,path,solution);
        return solution;
    }
    void pathSumHelper(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &solution) {
        if (root == NULL) {
            return;
        }

        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL && root->val == sum) {
            solution.push_back(path);
        }

        pathSumHelper(root->left, sum - root->val, path, solution);
        pathSumHelper(root->right, sum - root->val, path, solution);

        path.pop_back();
    }
};
