/*
159. Longest Substring with At Most Two Distinct Characters
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
Example 1:
Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:
Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.

From <https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/>


*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char,int> myMap;
        int res = 0;
        int start = 0, n = 0;

        for (int i = 0; i < int(s.length()); i++) {
            myMap[s[i]]++;
            if (myMap[s[i]] == 1) {
                n++;
            }
            while (n > 2) {
                myMap[s[start]]--;
                if (myMap[s[start]] == 0) {
                    n--;
                }
                start++;
            }
            res = max(res, i - start + 1);
        }

        return res;
    }
};

