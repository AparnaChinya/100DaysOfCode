/*
16. 3Sum Closest
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

From <https://leetcode.com/problems/3sum-closest/description/>


*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[3];
        sort(nums.begin(),nums.end());
        for(int first = 0; first < nums.size()-2; first++) {
            int second = first+1;
            int third = nums.size()-1;

            while(second < third) {
                int sum = nums[second] + nums[first] + nums[third];
                if(sum == target) {
                    return target;
                }
                if(abs(target-sum) < abs(target-closest)) {
                    closest = sum;
                }
                if(sum > target) {
                    third--;
                } else if(sum < target) {
                    second++;
                }

            }
        }

        return closest;
    }
};

