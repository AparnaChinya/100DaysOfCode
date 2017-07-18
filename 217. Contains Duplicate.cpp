/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 

From <https://leetcode.com/problems/contains-duplicate/> 

*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
        if(nums.size()==1)return false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[i+1]) return true;
        }
       return false;     
        
    }
};

