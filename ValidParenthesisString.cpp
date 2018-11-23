/*
678. Valid Parenthesis String
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
	1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
	2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
	3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
	4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
	5. An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
	1. The string size will be in the range [1, 100].

From <https://leetcode.com/problems/valid-parenthesis-string/description/>
*/

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(int i = 0; i < s.length(); i++) {
            low += s[i] == '(' ? 1 : -1;
            high += s[i] != ')' ? 1 : -1;
            if(high < 0) {
                break;
            }
            low = max(low,0);
        }
        return low == 0;
    }
};

