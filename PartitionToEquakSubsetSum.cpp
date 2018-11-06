/*
416. Partition Equal Subset Sum
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
Note:
	1. Each of the array element will not exceed 100.
	2. The array size will not exceed 200.
Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

From <https://leetcode.com/problems/partition-equal-subset-sum/description/>
*/

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) {
            return false;
        }
        sum = sum/2;
        vector<int> DP(sum+1);
        DP[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum; j >= nums[i]; j--) {
                DP[j] = DP[j] | DP[j-nums[i]];
            }
        }

        return DP[sum];
    }
};

