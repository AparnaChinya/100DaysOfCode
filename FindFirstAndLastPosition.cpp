/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

From <https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/>

*/

class Solution {
public:
    int findIndex(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size();

        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] < target) {
                low++;
            } else {
                high--;
            }
        }

        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int index1 = findIndex(nums,target);
        int index2 = findIndex(nums,target+1)-1;
        if(index1 < nums.size() && nums[index1] == target) {
            return {index1,index2};
        }
        return {-1,-1};
    }
};

