/*
643. Maximum Average Subarray I
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
	1. 1 <= k <= n <= 30,000.
	2. Elements of the given array will be in the range [-10,000, 10,000].

From <https://leetcode.com/problems/maximum-average-subarray-i/description/>
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN;
        double sum = 0.0;
        for(int i=0; i < nums.size(); i++) {
            if(i < k) {
                sum += nums[i];
            } else {
                res = max(res,sum);
                sum += nums[i] - nums[i-k];
            }
        }
        res = max(res,sum);
        return res/k;
    }
};

