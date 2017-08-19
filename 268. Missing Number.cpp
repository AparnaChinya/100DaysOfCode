/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array. 
For example,
Given nums = [0, 1, 3] return 2. 
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? 
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int max = 0;
        int Sum=0;
        
        int Flag=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) Flag=1;
            
            if(nums[i]>max) max = nums[i];
            
            Sum+=nums[i];
            
        }
        
        int originalSum = max*(max+1)/2;
        
        if(!Flag) return 0;
        
        return (originalSum==Sum)?max+1: originalSum-Sum;
            
        
    }
};