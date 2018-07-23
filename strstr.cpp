/*
Implement strStr()

Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

From <https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1161/>
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0 ) {
            return 0;
        }
        //Start with the first index of haystack
        for(int i = 0; i < haystack.length(); i++) {
           //Check if the needle first alphabet matches
            if(haystack[i] == needle[0]) {
                int j;
                //For entire length of the needle check if the haystack alphabet matches
                for(j = 0; j < needle.length(); j++){
                   //If it doesnt match break
                    if(haystack[i+j] != needle[j]) {
                        break;
                    }
                }
                //if the match happens for entire size of needle, we have the result
                if(j == needle.length()) {
                    return i;
                }

            }
        }

        return -1;
    }
};

