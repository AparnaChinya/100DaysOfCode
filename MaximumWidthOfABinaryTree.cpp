/*
662. Maximum Width of Binary Tree
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
Example 1:
Input:
1
         /   \
        3     2
       / \     \
      5   3     9
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:
1
         /
        3
       / \
      5   3
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:
1
         / \
        3   2
       /
      5
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:
1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
Note: Answer will in the range of 32-bit signed integer.

From <https://leetcode.com/problems/maximum-width-of-binary-tree/description/>
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
        int width;
    } ;


    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int answer = INT_MIN;
        queue<QueueEntry> myQueue;
        QueueEntry q = {root,1};
        myQueue.push(q);

        while(!myQueue.empty()) {
            int size = myQueue.size();
            int left = myQueue.front().width;
            int right = left;

            for(int i = 0; i < size; i++) {
                auto temp = myQueue.front();
                myQueue.pop();
                right = temp.width;
                if(temp.node->left) {
                    q = {temp.node->left,temp.width * 2};
                    myQueue.push(q);
                }
                if(temp.node->right) {
                    q = {temp.node->right, temp.width * 2 + 1};
                    myQueue.push(q);
                }
            }
            answer = max(answer,right + 1 - left);
        }

        return answer;
    }
};

