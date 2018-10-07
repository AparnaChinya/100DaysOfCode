/*
Maximum Binary Tree
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
	1. The root is the maximum number in the array.
	2. The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
	3. The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.
Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:
6
    /   \
   3     5
    \    /
     2  0
       \
        1
Note:
	1. The size of the given array will be in the range [1,1000].

From <https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/486>
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

    TreeNode *constructHelper(vector<int> &nums, int start, int end) {
        if(start > end) {
            return NULL;
        }

        int indexOfMax = start;

        //Find maximum number
        for(int i = start; i <= end; i++) {
            if(nums[i] > nums[indexOfMax]) {
                indexOfMax = i;
            }
        }

        //Build a node
        TreeNode *root = new TreeNode(nums[indexOfMax]);
        root->left = constructHelper(nums,start,indexOfMax-1);
        root->right = constructHelper(nums,indexOfMax+1,end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) {
            return NULL;
        }
        return constructHelper(nums,0,nums.size()-1);
    }
};

