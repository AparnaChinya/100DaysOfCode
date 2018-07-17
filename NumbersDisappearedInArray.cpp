/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
From <https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/>

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int j = abs(nums[i])-1;
            nums[j] = (nums[j] > 0) ? nums[j] * -1 : nums[j];
        }
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result.push_back(i+1);
            }
        }
        return result;
    }
};
