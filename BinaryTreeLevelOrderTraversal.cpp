/*
102. Binary Tree Level Order Traversal

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

From <https://leetcode.com/problems/binary-tree-level-order-traversal/description/>

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

        //Used BFS as it is level order Traversal
        vector<vector<int>> result;
        queue<TreeNode *> myQueue;

        if(root == NULL) {
            return result;
        }

        myQueue.push(root);
        vector<int> temp;
        temp.push_back(root->val);
        result.push_back(temp);

       //Push each node into the queue
        while(myQueue.size() != 0) {

            int sizeOfQueue = myQueue.size();

            vector<int> listOfValues;

            //For all the nodes in the queue.
            for(int i = 0 ; i < sizeOfQueue; i++) {
                TreeNode *temp = myQueue.front();
                if(temp->left != NULL) {
                    myQueue.push(temp->left);
                    listOfValues.push_back(temp->left->val);
                }
                 if(temp->right != NULL) {
                    myQueue.push(temp->right);
                    listOfValues.push_back(temp->right->val);
                }

                 myQueue.pop();
            }
            //Add a paritcular layers nodes into the result
            if(listOfValues.size() != 0) {
                 result.push_back(listOfValues);
            }

        }

        return result;


    }
};

