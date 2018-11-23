/*
312. Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
Note:
	• You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
	• 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:
Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

From <https://leetcode.com/problems/burst-balloons/description/>
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> DP(nums.size(),vector<int>(nums.size(),0));

        //For length from 1 to n
        for(int len = 1; len <= n; len++) {
            for(int left = 1; left <= n - len + 1; left++) {
                int right = left + len - 1;
                for(int k = left; k<= right; k++) {
                    DP[left][right] = max(DP[left][right],
                                          nums[left-1]* nums[k] * nums[right+1] + DP[left][k-1] + DP[k+1][right]);
                }
            }
        }

        return DP[1][n];
    }
};

