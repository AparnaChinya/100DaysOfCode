/*
Find Duplicate Subtrees

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any oneof them.
Two trees are duplicate if they have the same structure with same node values.
Example 1:
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.

From <https://leetcode.com/problems/find-duplicate-subtrees/description/>
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
    string dfs(TreeNode *node, unordered_map<string,vector<TreeNode*>> &myMap) {
        if(node == NULL) {
            return "";
        }
        string s = "(" +  dfs(node->left,myMap) + to_string(node->val) + dfs(node->right,myMap) + ")";
        myMap[s].push_back(node);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> myMap;
        vector<TreeNode*> answer;
        dfs(root,myMap);
        for(auto i = myMap.begin(); i!= myMap.end(); i++) {
            if(i->second.size() > 1)
                answer.push_back(i->second[0]);
        }
        return answer;
    }
};

