/*
Valid Parentheses
  Go to Discuss
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
	1. Open brackets must be closed by the same type of brackets.
	2. Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Example 1:
Input: "()"
Output: true
Example 2:
Input: "()[]{}"
Output: true
Example 3:
Input: "(]"
Output: false
Example 4:
Input: "([)]"
Output: false
Example 5:
Input: "{[]}"
Output: true

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/179/>

*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                myStack.push(s[i]);
            }
            else if(s[i] == ')') {
                if(!myStack.empty() && myStack.top() == '(') {
                    myStack.pop();
                } else {
                    return false;
                }
            } else if(s[i] == '}') {
                if(!myStack.empty() && myStack.top() == '{') {
                    myStack.pop();
                } else {
                    return false;
                }
            } else if(s[i] == ']') {
                if(!myStack.empty() && myStack.top() == '[') {
                    myStack.pop();
                } else {
                    return false;
                }
            }
        }
        if(myStack.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};

