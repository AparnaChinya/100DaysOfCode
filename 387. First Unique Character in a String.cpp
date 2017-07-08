/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1. 
Examples: 
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. 

From <https://leetcode.com/problems/first-unique-character-in-a-string/> 
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> check;
             
        
        for(int i=0;i<s.length();i++)
        {
            check[s[i]]+=1;
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(check[s[i]]==1) return i;
        }
        
        return -1;
        
    }
};

