/*
844. Backspace String Compare
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:
	1. 1 <= S.length <= 200
	2. 1 <= T.length <= 200
	3. S and T only contain lowercase letters and '#' characters.
Follow up:
	• Can you solve it in O(N) time and O(1) space?

From <https://leetcode.com/problems/backspace-string-compare/description/>
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> myStack;

        for(int i = 0; i < S.size(); i++) {
            if(S[i] != '#') {
                myStack.push(S[i]);
            } else if(S[i] == '#' && !myStack.empty()) {
                myStack.pop();
            }
        }
        string s = "";
        while(!myStack.empty()) {
            s += myStack.top();
            myStack.pop();
        }

        for(int i = 0; i < T.size(); i++) {
            if(T[i] != '#') {
                myStack.push(T[i]);
            } else if(T[i] == '#' && !myStack.empty()) {
                myStack.pop();
            }
        }
        string t = "";
        while(!myStack.empty()) {
            t += myStack.top();
            myStack.pop();
        }

        return s == t;
    }
};

