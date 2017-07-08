
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

From <https://leetcode.com/problems/majority-element/> 


*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> myMap;
        
        for(int i=0;i<nums.size();i++)
        {
            myMap[nums[i]]++;
            if(myMap[nums[i]]>(nums.size()/2)) return nums[i];
            
        }
        
       // return 0;
    }
};
