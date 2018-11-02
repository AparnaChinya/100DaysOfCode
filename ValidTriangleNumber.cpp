/*
611. Valid Triangle Number
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
	1. The length of the given array won't exceed 1000.
	2. The integers in the given array are in the range of [0, 1000].

From <https://leetcode.com/problems/valid-triangle-number/description/>


*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        if(nums.size() < 3) {
            return 0;
        }
        for(int first = 0; first < nums.size()-2; first++) {
            int third = first + 2;
            for(int second = first+1; second < nums.size()-1 && nums[first] != 0; second++) {
                while(third < nums.size() && nums[first]+nums[second] > nums[third]) {
                    third++;
                }
                count += third - second - 1;
            }
        }
        return count;
    }
};

g