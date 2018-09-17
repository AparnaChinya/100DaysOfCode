/*
Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.
Examples 1:
Input: [3,9,20,null,null,15,7]
3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
Output:
[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:
Input: [3,9,8,4,0,1,7]
3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
Output:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:
Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)
3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
Output:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

From <https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/493/>

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<int,TreeNode*>> myQueue;

        //We need map as the index can be negative when root is considered as 0 index and left of root is -1, right of root is +1
        map<int,vector<int>> result;
        vector<vector<int>> answer;

        if(root == NULL) {
            return answer;
        }

        if(root != NULL) {
            myQueue.push(make_pair(0,root));
        }

        //Apply BFS to traverse the tree
        while(!myQueue.empty()) {
            int size = myQueue.size();
            for(int i = 0; i < size; i++) {
                auto temp = myQueue.front();
                cout << temp.first << " " << temp.second->val << endl;
                result[temp.first].push_back(temp.second->val);
                myQueue.pop();

                if(temp.second->left != NULL) {
                    myQueue.push(make_pair(temp.first-1,temp.second->left));
                }
                if(temp.second->right != NULL) {
                    myQueue.push(make_pair(temp.first+1,temp.second->right));
                }
            }
        }

        for(auto item : result) {
            answer.push_back(item.second);
        }

        return answer;
    }
};

