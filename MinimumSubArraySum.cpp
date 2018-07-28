/* Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
Example: 
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

From <https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1299/>  */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int result = INT_MAX;
      /* Minimum Size Subarray Sum

      Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
      Example: 
      Input: s = 7, nums = [2,3,1,2,4,3]
      Output: 2
      Explanation: the subarray [4,3] has the minimal length under the problem constraint.
      Follow up:
      If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

      From <https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1299/>  */

      class Solution {
      public:
          int minSubArrayLen(int s, vector<int>& nums) {
              int sum = 0;
              int left = 0;
              int result = INT_MAX;

              //Best method, take O(n) time
              for(int i = 0 ; i < nums.size(); i++) {
                  sum += nums[i];

                  //while the sum is greater than the target, keep track of the number of positions required to get there
                  while(sum >= s) {
                      sum -= nums[left];
                      result = min(result, i+1-left);
                      left++;
                  }
              }

              return result == INT_MAX ? 0 : result;
          }
      };


        //Best method, take O(n) time
        for(int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];

            //while the sum is greater than the target, keep track of the number of positions required to get there
            while(sum >= s) {
                sum -= nums[left];
                result = min(result, i+1-left);
                left++;
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};

