/*
259. 3Sum Smaller
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
Example:
Input: nums = [-2,0,1,3], and target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?

From <https://leetcode.com/problems/3sum-smaller/description/>

*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3 ) {
            return 0;
        }
        int count = 0;
        sort(nums.begin(),nums.end());

        for(int first = 0; first < nums.size()-2; first++) {
            if(nums[first] + nums[first+1] + nums[first+2] >= target) {
                break;
            }
            int second = first+1;
            int third = nums.size()-1;

            while(second < third) {
                while(second < third && nums[first] + nums[second] + nums[third] >= target) {
                    third--;
                }
                count += third-second;
                second++;
            }
        }
        return count;
    }
};

