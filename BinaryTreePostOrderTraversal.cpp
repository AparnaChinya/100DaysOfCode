/*
145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?


From <https://leetcode.com/problems/binary-tree-postorder-traversal/description/>

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        vector<int> result;

        if(root == NULL) {
            return result;
        }
        myStack.push(root);

        while(!myStack.empty()) {
            auto temp = myStack.top(); myStack.pop();
            //remember to add in the front
            result.insert(result.begin(),temp->val);

            if(temp->left != NULL) {
                myStack.push(temp->left);
            }
            if(temp->right != NULL) {
                myStack.push(temp->right);
            }
        }

        return result;

    }
};

