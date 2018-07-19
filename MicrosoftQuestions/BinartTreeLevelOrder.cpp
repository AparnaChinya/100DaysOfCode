/*
Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

From <https://leetcode.com/explore/interview/card/microsoft/31/trees-and-graphs/164/>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //BFS implemented
        vector<vector<int>> result;

        if(root == NULL) {
            return result;
        }
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        result.push_back(vector<int>());

        result[0].push_back(root->val);

        while(!myQueue.empty()) {
            vector<int> eachLevel;
            int size = myQueue.size();

            for(int i = 0; i < size; i++) {
                //Dont forget to pop front of queue inside the for loop
                TreeNode *temp = myQueue.front();
                myQueue.pop();

                if(temp->left != NULL) {
                    myQueue.push(temp->left);
                    eachLevel.push_back(temp->left->val);
                }
                if(temp->right != NULL) {
                    myQueue.push(temp->right);
                    eachLevel.push_back(temp->right->val);
                }
            }
            //Dont forget to check if eachLevel count is greater than 0
            if(eachLevel.size() > 0)
                result.push_back(eachLevel);
        }
        return result;
    }
};

