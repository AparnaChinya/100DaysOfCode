/*

Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".

From <https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1183/>  */
class Solution {
public:
    string reverseString(string s) {

        int endPointer = s.size()-1;
        if(s.length() == 0 || s.length() == 1) {
            return s;
        }
        // Traverse half while simultaneously switching in the first and end index alphabets
        for(int i = 0; i < s.length()/2; i++) {
            char temp = s[endPointer];
            s[endPointer] = s[i];
            s[i] = temp;
            endPointer--;
        }

        return s;
    }
};



