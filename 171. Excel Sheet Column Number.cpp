/*

Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

From <https://leetcode.com/problems/excel-sheet-column-number/> 

*/

class Solution {
public:
    int titleToNumber(string s) {
        
        unordered_map<char,int> myMap;
        
        char alph = 'A';
        for(int i=0;i<26;i++)
        {
           myMap[alph] = i+1;
            alph++;
        }
        
        int Sum=0;
        for(int i=0;i<s.size();i++)
        {
            Sum= Sum*26 + myMap[s[i]];
        }
        
        return Sum;
        
    }
};

