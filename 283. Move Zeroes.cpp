/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. 
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 
Note:
	1. You must do this in-place without making a copy of the array.
	2. Minimize the total number of operations.

From <https://leetcode.com/problems/move-zeroes/> 


*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
     int count = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[count++]=nums[i];
            }
        }
        
        for(;count<nums.size();count++)
            nums[count]=0;
        
        
        
    }
};

