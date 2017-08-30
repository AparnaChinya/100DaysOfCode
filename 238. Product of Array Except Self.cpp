/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6]. 
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
       int n = nums.size();
        vector<int> Left(n);
        vector<int> Right(n);
        vector<int> result;
        
        Left[0] = 1;
        Right[nums.size()-1]= 1;
        int r;
                
        for(int i=1;i<nums.size();i++)
        {
            Left[i] = Left[i-1]*nums[i-1];
        }
        
        for(int j=nums.size()-2;j>=0;j--)
        {
            Right[j] = Right[j+1]*nums[j+1];
        }
        
        for(int j=0;j<nums.size();j++)
        {
            r = Left[j]*Right[j];
            
            result.push_back(r);
            
            
        }
        
        return result;
        
    }
};