/*
 * Valid Palindrome
  Go to Discuss
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        if(end < 0) {
            return true;
        }
        while (start < end) {
            cout<< s[start] << " " << s[end] << endl;
            while(!isalnum(s[start])) {
                start++;
            }
            while(!isalnum(s[end])) {
                end--;
            }
            //Remember to check start < end for testCases like ",."

            if(toupper(s[start]) != toupper(s[end]) && start < end) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};