/*
107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]


From <https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/>
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
    struct QueueEntry {
        TreeNode *node;
        int depth;
    };
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        queue<QueueEntry> myQueue;
        vector<vector<int>> result;

        QueueEntry q = {root,0};
        myQueue.push(q);
        result.push_back(vector<int>());
        result[0].push_back({root->val});

        while(!myQueue.empty()) {
            int size = myQueue.size();
            vector<int> myVector;

            for(int i = 0; i < size; i++) {
                auto qFront = myQueue.front();
                myQueue.pop();

                if(qFront.node->left != NULL) {
                    myVector.push_back(qFront.node->left->val);
                    myQueue.push({qFront.node->left,qFront.depth+1});
                }
                if(qFront.node->right != NULL) {
                    myVector.push_back(qFront.node->right->val);
                    myQueue.push({qFront.node->right,qFront.depth+1});
                }
            }
            if(myVector.size() > 0) {
                result.push_back(myVector);
            }

        }
        reverse(result.begin(), result.end());

        return result;
    }
};

