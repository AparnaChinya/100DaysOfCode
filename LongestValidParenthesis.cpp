/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

From <https://leetcode.com/problems/longest-valid-parentheses/description/>
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int maxlength = INT_MIN;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if(left == right) {
                maxlength = max(maxlength,2*left);
            } else
            if(right >= left) {
                left = 0; right = 0;
            }
        }

        left = 0; right = 0;

        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if(left == right) {
                maxlength = max(maxlength,2*left);
            } else
            if(left >= right) {
                left = 0; right = 0;
            }
        }

        return maxlength == INT_MIN ? 0 : maxlength;
    }
};

