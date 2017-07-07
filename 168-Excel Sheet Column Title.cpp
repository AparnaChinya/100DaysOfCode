/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

From <https://leetcode.com/problems/excel-sheet-column-title/> 

*/

class Solution {
public:
    string convertToTitle(int n) {
        
        unordered_map<char,int>  myMap;
        int x =1;
        myMap[0] = 'Z';
         for(char i='A';i<'Z';i++)
        {
           myMap[x++] = i;
            
        }
        
        string ans = "";
        
        while(n)
        {
            int x = n%26;
            ans = char(myMap[x]) + ans;
            n=(n-1)/26;
            
        }
        
        return ans;
    }
};

