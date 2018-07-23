/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.

From <https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1162/>

*/

class Solution {
public:

    string prefixHelper(string first, string second) {
        string result = ""; int j = 0;
        // return common prefix between the two strings
        for(int i = 0; i < first.length(); i++) {
            if (first[i] == second[j]) {
                    result += second[j];
                j++;
             } else {
                break;
            }
        }
        return result;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string first = strs[0];
        //check for common prefix of the first string and rest, replace first string with the common prefix
        for(int i = 1; i < strs.size(); i++) {
            first = prefixHelper(first,strs[i]);
        }
        return first;
    }
};
