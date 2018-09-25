/* Maximum Size Subarray Sum Equals k
  Go to Discuss
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
Example 1:
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?

From <https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/524/>
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLength = INT_MIN;
        int sum = 0;
        unordered_map<int,int> myMap;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum == k) {
                maxLength = i +1;
            }

            if(myMap.find(sum) == myMap.end()) {
                myMap[sum] = i;
            }

            if(myMap.find(sum-k) != myMap.end()) {
                maxLength = max(maxLength, i-myMap[sum-k]);
            }
        }

        return maxLength == INT_MIN ? 0 : maxLength;
    }
};

