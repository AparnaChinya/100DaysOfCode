/*
Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:
	• The input array will only contain 0 and 1.
	• The length of input array is a positive integer and will not exceed 10,000

From <https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1301>
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int tempOnes = 0;
        // Traverse through the vector
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                tempOnes++;
            } else {
                //Reset
               tempOnes = 0;
            }
            //Store the maxOne number
            maxOnes = max(maxOnes,tempOnes);
        }
        return maxOnes;
    }
};

