/*
152. Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

From <https://leetcode.com/problems/maximum-product-subarray/description/>

*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minHere = nums[0];
        int maxHere = nums[0];
        int product = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(minHere,maxHere);
            }
            minHere = min(nums[i],nums[i] * minHere);
            maxHere = max(nums[i],nums[i] * maxHere);

            product = max(product,maxHere);
        }
        return product;

    }
};

