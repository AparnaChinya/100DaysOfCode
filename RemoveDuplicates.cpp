/*
316. Remove Duplicate Letters
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example 1:
Input: "bcabc"
Output: "abc"
Example 2:
Input: "cbacdcbc"
Output: "acdb"

From <https://leetcode.com/problems/remove-duplicate-letters/description/>
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> myMap;
        vector<bool> visited(256,false);
        string result = "0";
        for(int i = 0; i < s.length(); i++) {
            myMap[s[i]]++;
        }

        for(char x : s) {
            myMap[x]--;
            if(visited[x]) {
                continue;
            }
            while(x < result.back() && myMap[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            visited[x] = true;
            result += x;
        }

        return result.substr(1);
    }
};
