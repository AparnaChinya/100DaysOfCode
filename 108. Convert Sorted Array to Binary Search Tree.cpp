/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()==0) return NULL;
        
        int midpoint = nums.size()/2;
        
        TreeNode* t = new TreeNode(nums[midpoint]);
        
        vector<int> LeftArray,RightArray;
        
        for(int i=0;i<midpoint;i++)
        {
            LeftArray.push_back(nums[i]);
            
        }
        for(int i=midpoint+1;i<nums.size();i++)
        {
            RightArray.push_back(nums[i]);
            
        }
        
        t->left = sortedArrayToBST(LeftArray);
        t->right = sortedArrayToBST(RightArray);
        
        
        return t;
        
    }        
};