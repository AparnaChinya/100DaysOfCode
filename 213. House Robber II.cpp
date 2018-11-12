/*
213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

From <https://leetcode.com/problems/house-robber-ii/description/>

*/

class Solution {
public:
    int helper(vector<int> &nums, int left, int right) {
        int previous = 0;
        int current = 0;

        for(int i = left; i <= right; i++) {
            int temp = max(current,previous + nums[i]);
            previous = current;
            current = temp;
        }

        return current;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return max(nums[0],nums[1]);
        }
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};

