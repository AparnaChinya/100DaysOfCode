/*
Q: https://leetcode.com/problems/3sum
15. 3Sum 

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
 vector<vector<int>> threeSum(vector<int>& nums) {

	std::sort(nums.begin(),nums.end());
    
     vector<vector<int>> result;
     
     int Sum,Target,Front,Rear;
     
     for(int i =0;i<nums.size();i++)
     {
         Target = -nums[i];
         Front =i+1;
         Rear = nums.size()-1;
         
         while(Front<Rear)
         {         
         Sum = nums[Front] + nums[Rear];
         
         if(Sum < Target)Front++;
         
         else if(Sum > Target) Rear--;
         
         else if(Sum==Target)
         {
             vector<int> triplet(3,0);
             triplet[0]=nums[i];
             triplet[1]=nums[Front];
             triplet[2]=nums[Rear];
             result.push_back(triplet);
            
             while(Front<Rear && nums[Front]==triplet[1])Front++;
             while(Front<Rear && nums[Rear]==triplet[2])Rear--;
              
         	}
         }
         
         while(i+1<nums.size() && nums[i]==nums[i+1])i++;
         
         
     }
     
     return result;


}

};