/*
647. Palindromic Substrings
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
	1. The input string length won't exceed 1000.

From <https://leetcode.com/problems/palindromic-substrings/description/>

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        if(s == "") {
            return false;
        }
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int countSubstrings(string s) {
        if(s.length() == 0) {
            return true;
        }
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            for(int j = 1; j <= s.length()-i; j++) {
                if(isPalindrome(s.substr(i,j))) {
                    count++;
                }
            }
        }
        return count;
    }
};


