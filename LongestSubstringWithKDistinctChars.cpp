/*
340. Longest Substring with At Most K Distinct Characters
Given a string, find the length of the longest substring T that contains at most k distinct characters.
Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

From <https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/>


*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char,int> myMap;
        int res = 0;
        int start = 0, n = 0;

        for (int i = 0; i < int(s.length()); i++) {
            myMap[s[i]]++;
            if (myMap[s[i]] == 1) {
                n++;
            }
            while (n > k) {
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

