/*
Discuss Editorial Solution Pick One 


Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

From <https://leetcode.com/problems/single-number/> 



*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
       int result=0;
        
        for(int i=0;i<nums.size();i++)
        {
            result = result ^ nums[i];
        }
        
        return result;
    }
};

