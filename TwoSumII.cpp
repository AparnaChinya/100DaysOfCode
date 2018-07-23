/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Note:
	• Your returned answers (both index1 and index2) are not zero-based.
	• You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

From <https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1153/>


*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0;

        int right = numbers.size() - 1;
        // Binary Search
        while (left <= right) {
            if (numbers[left] + numbers[right] == target) {
                // Add +1 as it is not 0 based
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else {
                left++;
            }
        }


    }
};
