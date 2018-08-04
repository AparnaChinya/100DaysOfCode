/* In a given integer array nums, there is always exactly one largest element.
Find whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, otherwise return -1.
Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 
Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 
Note:
	1. nums will have a length in the range [1, 50].
	2. Every nums[i] will be an integer in the range [0, 99].

From <https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/>  */

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int index = 0;

        for(int i=0; i < nums.size(); i++){

            if(nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
                index = i;
            } else if(nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }

        if(firstMax >= 2*secondMax) {
            return index;
        }
        return -1;
    }
};
