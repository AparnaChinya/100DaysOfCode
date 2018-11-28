/*
*95.UniqueBinarySearchTreesII
DescriptionHintsSubmissionsDiscussSolution
Givenanintegern,generateallstructurallyuniqueBST's(binarysearchtrees)thatstorevalues1...n.

Example:

Input:3
Output:
[
[1,null,3,2],
[3,2,null,1],
[3,1,null,null,2],
[2,1,3],
[1,null,2,null,3]
]
Explanation:
Theaboveoutputcorrespondstothe5uniqueBST'sshownbelow:

13321
\///\\
321132
//\\
2123
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
    vector<TreeNode*> generate(int start, int end) {
        if(start > end) {
            return {NULL};
        }
        vector<TreeNode*> trees;
        for(int i = start; i <= end; i++) {

            for(TreeNode * leftRoot : generate(start,i-1)) {
                for(TreeNode *rightRoot : generate(i+1,end)) {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftRoot;
                    node->right = rightRoot;
                    trees.push_back(node);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return {};
        }
        return generate(1,n);
    }
};


