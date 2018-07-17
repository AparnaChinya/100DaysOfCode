/*
560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
	1. The length of the array is in range [1, 20,000].
	2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

From <https://leetcode.com/problems/subarray-sum-equals-k/description/>

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if(sum == k) {
                    result++;
                }
            }

        }

        return result;
    }
};

