/* Longest Palindromic Substring
  Go to Discuss
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"

From <https://leetcode.com/explore/interview/card/microsoft/30/array-and-strings/180/>
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) {
            return s;
        }
        bool DP[s.length()][s.length()] = {false};
        int maxLength = 1;
        int startIndexOfString = 0;
        //for 1 length characters
        for(int i = 0; i < s.length(); i++) {
            DP[i][i] = true;
        }

        //for 2 length character
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == s[i+1]) {
                DP[i][i+1] = true;
                maxLength = 2;
                startIndexOfString = i;
            }
        }

        //for 3 length and more length characters
        for(int charLength = 3; charLength <= s.length(); charLength++) {
            for(int startIndex = 0; startIndex < s.length() - charLength + 1; startIndex++) {
                int endIndex = startIndex + charLength - 1;
                if(DP[startIndex+1][endIndex-1] && s[startIndex] == s[endIndex]) {
                    DP[startIndex][endIndex] = true;
                    if(charLength > maxLength) {
                        maxLength = charLength;
                        startIndexOfString = startIndex;
                    }
                }
            }
        }
        string result ="";
        int endIndexOfString = startIndexOfString + maxLength - 1;
        for(int i = startIndexOfString; i <= endIndexOfString; ++i) {
            result += s[i];
        }
        return result;
    }
};


