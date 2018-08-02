
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

From <https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1165/>  */

class Solution {
public:
    string reverseWords(string s) {
        int previous = 0;

        for(int i = 0; i <= s.length(); i++) {
            int k = i;
            while(s[i] != ' ' && i < s.length()) {
                i++;
            }
            previous = k;
            reverse(s.begin() + previous, s.end() + i);
        }
        return s;
    }
};

