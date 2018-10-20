863. All Nodes Distance K in Binary Tree
        We are given a binary tree (with root node root), a target node, and an integer value K.
Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
 
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
Explanation:
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 
Note:
1. The given tree is non-empty.
2. Each node in the tree has unique values 0 <= node.val <= 500.
3. The target node is a node in the tree.
4. 0 <= K <= 1000.

From <https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/>
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
    map<TreeNode*,TreeNode*> myMap;
    set<TreeNode*> visited;
    vector<int> result;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL) {
            return {};
        }
        populateParent(root);
        dfs(target,K);
        return result;
    }

    void dfs(TreeNode *root, int K) {
        if(visited.find(root) != visited.end()) {
            return;
        }
        visited.insert(root);
        if(K == 0) {
            result.push_back(root->val);
            return;
        }
        if(root->left) {
            dfs(root->left,K-1);
        }
        if(root->right) {
            dfs(root->right,K-1);
        }
        TreeNode *p = myMap[root];
        if(p) {
            dfs(p,K-1);
        }
    }

    void populateParent(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        if(root->left) {
            myMap[root->left] = root;
            populateParent(root->left);
        }
        if(root->right) {
            myMap[root->right] = root;
            populateParent(root->right);
        }
    }
};

